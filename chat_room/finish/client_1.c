#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <termios.h>
#include <sys/stat.h>
#include <pthread.h>
#include <fcntl.h>
#include <time.h>
#define PORT 8888
#include "cJSON.h"
#define CHAT_PRI 4
#define LOGIN 5
#define REGISTER 6
#define GET_GROUP_LIST 7
#define CREAT_GROUP 8
#define ADD_MEMBER 9
#define ADD_FRIEND 10
#define AGREE 11
#define DISAGREE 12
#define FRIEND_REPLY 13
#define NO_SPEAKING 14 //禁言　　　
#define CHAT_GROUP 15
#define SEND_FILE 16      //上传文件
#define SPEAKING 17       //解除禁言
#define ADD_USR 18        //添加好友
#define DELETE_FRIEND 19  //删除好友
#define GET_FRI_LIST 20   //获得好友列表
#define GROUP_USR_LST 21  //获得群列表
#define QUIT_GROUP 22     //删除群成员
#define QUIT_GROUP_T 23   //　退群
#define ADD_GROUP 24      //加群
#define SEND_FILE_RPLY 25 //发文件请求
#define WRONG_CODE 26     //密码问题
#define LOOK_PRIVATE 27   //查看私聊记录
#define LOOK_GROUP 28     // 查看群聊记录
char friend[30];
char pmsg[100][100]; //临时储存私聊记录
char gmsg[100][100]; //临时储存群聊记录
int uid;
int count;
int flag = 0;
int i = 0;
pthread_mutex_t mutex;
typedef struct package
{
    char name[20];
    char send_name[20];
    char recv_name[20];
    int send_fd;
    int recv_fd;
    char timep[20];
    char content[100];
} PACK;
typedef struct friend_info
{
    int id;
    int pid;
    int status;
} FRIEND_INFO;
int getch(void)
{
    struct termios tm, tm_old;
    int fd = 0, ch;
    if (tcgetattr(fd, &tm) < 0)
    { //保存现在的终端设置
        return -1;
    }
    tm_old = tm;
    cfmakeraw(&tm); //更改终端设置为原始模式，该模式下所有的输入数据以字节为单位被处理
    if (tcsetattr(fd, TCSANOW, &tm) < 0)
    { //设置上更改之后的设置
        return -1;
    }
    ch = getchar();
    if (tcsetattr(fd, TCSANOW, &tm_old) < 0)
    { //更改设置为最初的样子
        return -1;
    }
    return ch;
}
//解码
/** 在字符串中查询特定字符位置索引*/
int num_strchr(const char *str, char c)
{
    const char *pindex = strchr(str, c);
    if (NULL == pindex)
    {
        return -1;
    }
    return pindex - str;
}
const char *base64char = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
const char padding_char = '=';
int base64_encode(const unsigned char *sourcedata, char *base64, int datalength)
{
    int i = 0, j = 0;
    unsigned char trans_index = 0;
    for (; i < datalength; i += 3)
    {
        trans_index = ((sourcedata[i] >> 2) & 0x3f);
        base64[j++] = base64char[(int)trans_index];
        trans_index = ((sourcedata[i] << 4) & 0x30);
        if (i + 1 < datalength)
        {
            trans_index |= ((sourcedata[i + 1] >> 4) & 0x0f);
            base64[j++] = base64char[(int)trans_index];
        }
        else
        {
            base64[j++] = base64char[(int)trans_index];

            base64[j++] = padding_char;

            base64[j++] = padding_char;

            break;
        }
        trans_index = ((sourcedata[i + 1] << 2) & 0x3c);
        if (i + 2 < datalength)
        {
            trans_index |= ((sourcedata[i + 2] >> 6) & 0x03);
            base64[j++] = base64char[(int)trans_index];

            trans_index = sourcedata[i + 2] & 0x3f;
            base64[j++] = base64char[(int)trans_index];
        }
        else
        {
            base64[j++] = base64char[(int)trans_index];

            base64[j++] = padding_char;

            break;
        }
    }

    base64[j] = '\0';

    return 0;
}
/*解码*/
int base64_decode(const char *base64, unsigned char *dedata)
{
    int i = 0, j = 0;
    int trans[4] = {0, 0, 0, 0};
    for (; base64[i] != '\0'; i += 4)
    {
        trans[0] = num_strchr(base64char, base64[i]);
        trans[1] = num_strchr(base64char, base64[i + 1]);
        dedata[j++] = ((trans[0] << 2) & 0xfc) | ((trans[1] >> 4) & 0x03);

        if (base64[i + 2] == '=')
        {
            continue;
        }
        else
        {
            trans[2] = num_strchr(base64char, base64[i + 2]);
        }
        dedata[j++] = ((trans[1] << 4) & 0xf0) | ((trans[2] >> 2) & 0x0f);

        if (base64[i + 3] == '=')
        {
            continue;
        }
        else
        {
            trans[3] = num_strchr(base64char, base64[i + 3]);
        }

        dedata[j++] = ((trans[2] << 6) & 0xc0) | (trans[3] & 0x3f);
    }
    dedata[j] = '\0';

    return 0;
}
/*发包函数，美滋滋*/
void add_file_size(int fd, char *pass)
{
    int m = strlen(pass) + 4;
    char temp_pack[m + 1];
    temp_pack[m] = 0;
    strcpy(temp_pack + 4, pass);
    *(int *)temp_pack = strlen(pass);
    send(fd, &temp_pack, m, 0);
    return;
}

void reg(int sockfd) /*注册用户信息*/
{
    //char * pass = (char*)malloc(sizeof(char)*256);
    char usrname[4];
    char passwd[8];
    char st[8];
    char m[9];
    int i, c;
    char ch;
    int id;
    cJSON *json = cJSON_CreateObject();
    cJSON_AddNumberToObject(json, "signal", REGISTER);
    printf("please enter your id\n");
    scanf("%d", &id);
    cJSON_AddNumberToObject(json, "id", id);
    printf("Please enter your user name\n");
    scanf("%s", usrname);
    cJSON_AddStringToObject(json, "usrname", usrname);
    printf("Please enter the safe passwds(8 bits)\n");
    getchar();
    for (i = 0; i < 8; i++)
    {
        ch = getch();
        if (passwd[i] == '\n')
        {
            passwd[i] = '\0';
            break;
        }
        passwd[i] = ch;
    }
    passwd[i] = '\0';
    cJSON_AddStringToObject(json, "passwd", passwd);
    char *pass = cJSON_PrintUnformatted(json);
    add_file_size(sockfd, pass);
    /*  int number;
    recv(sockfd, &number, 4, 0);
    printf("fff\n");
    printf("%d\n", number);
    char *temp = (char *)malloc(sizeof(char) * number + 1);
    temp[number] = 0;
    recv(sockfd, temp, number, 0);
    printf("%s\n", temp);
    cJSON *node = cJSON_Parse(temp);
    printf("%s\n", cJSON_GetObjectItem(node, "content")->valuestring);
    cJSON_Delete(json);*/
}
/*找回密码*/
void back_passwd(int sockfd)
{
    cJSON *json = cJSON_CreateObject();
    int id;
    printf("请输入你的账号\n");
    scanf("%d", &id);
    cJSON_AddNumberToObject(json, "id", id);
    char *pass = cJSON_PrintUnformatted(json);
    add_file_size(sockfd, pass);
}
/*删除好友*/
void delete_usr(int sockfd)
{
    cJSON *json = cJSON_CreateObject();
    cJSON_AddNumberToObject(json, "signal", DELETE_FRIEND);
    int id;
    printf("please enter the id that you want to delete\n");
    scanf("%d", &id);
    cJSON_AddNumberToObject(json, "id", id);
    char *pass = cJSON_PrintUnformatted(json);
    cJSON_Delete(json);
    add_file_size(sockfd, pass);
}
/*添加好友*/
void add_friends(int sockfd, int uid)
{
    cJSON *json = cJSON_CreateObject();
    int pid;
    cJSON_AddNumberToObject(json, "signal", ADD_FRIEND);
    cJSON_AddNumberToObject(json, "uid", uid);
    printf("please enter the id of your friend\n");
    scanf("%d", &pid);
    cJSON_AddNumberToObject(json, "pid", pid);
    char *pass = cJSON_PrintUnformatted(json);
    printf("%s\n", pass);
    add_file_size(sockfd, pass);
}
int add_friends_reply(int sockfd, char *string)
{
    printf("%s\n", string);
    cJSON *node = cJSON_Parse(string);
    printf("%d请求添加你为好友(0 or 1)\n", cJSON_GetObjectItem(node, "uid")->valueint);
    int ch;
    scanf("%d", &ch);
    // cJSON_Delete(node);
    cJSON *json = cJSON_CreateObject();
    cJSON_AddNumberToObject(json, "signal", FRIEND_REPLY);
    cJSON_AddNumberToObject(json, "uid", cJSON_GetObjectItem(node, "uid")->valueint);
    if (ch == 1)
        cJSON_AddNumberToObject(json, "tip", AGREE);
    else
        cJSON_AddNumberToObject(json, "tip", DISAGREE);
    cJSON_AddNumberToObject(json, "pid", cJSON_GetObjectItem(node, "pid")->valueint);
    char *pass = cJSON_PrintUnformatted(json);
    cJSON_Delete(node);
    add_file_size(sockfd, pass);
    cJSON_Delete(json);
}
/*获得好友列表*/
void get_friend_list(int sockfd, int id)
{
    cJSON *json = cJSON_CreateObject();
    cJSON_AddNumberToObject(json, "signal", GET_FRI_LIST);
    cJSON_AddNumberToObject(json, "id", id);
    char *pass = cJSON_PrintUnformatted(json);
    add_file_size(sockfd, pass);
    cJSON_Delete(json);
}
/*获得群好友列表*/
int get_group_list(int sockfd, int id)
{
    cJSON *json = cJSON_CreateObject();
    cJSON_AddNumberToObject(json, "signal", GET_GROUP_LIST);
    printf("please enter the group id\n");
    int gid;
    scanf("%d", &gid);
    cJSON_AddNumberToObject(json, "gid", gid);
    char *pass = cJSON_PrintUnformatted(json);
    add_file_size(sockfd, pass);
    cJSON_Delete(json);
}
/*获得群列表*/
void group_usr_list(int sockfd, int id)
{
    cJSON *json = cJSON_CreateObject();
    cJSON_AddNumberToObject(json, "signal", GROUP_USR_LST);
    cJSON_AddNumberToObject(json, "id", id);
    char *pass = cJSON_PrintUnformatted(json);
    add_file_size(sockfd, pass);
    cJSON_Delete(json);
}
/*原始的分包函数*/
cJSON *analysis_package(int sockfd)
{
    int number;
    int m = recv(sockfd, &number, 4, 0);
    printf("%d\n", number);
    char *temp = (char *)malloc(sizeof(char) * number + 1);
    temp[number] = 0;
    recv(sockfd, temp, number, 0);
    printf("%s\n", temp);
    cJSON *node = cJSON_Parse(temp);
    free(temp);
    return node;
}
/*创建群聊*/
void create_group(int sockfd, int id)
{
    cJSON *json = cJSON_CreateObject();
    int gid;
    char buf[30];
    cJSON_AddNumberToObject(json, "signal", CREAT_GROUP);
    printf("please enter the group id\n");
    scanf("%d", &gid);
    cJSON_AddNumberToObject(json, "gid", gid);
    printf("please enter the group name\n");
    scanf("%s", buf);
    cJSON_AddStringToObject(json, "g_name", buf);
    cJSON_AddNumberToObject(json, "id", id);
    char *pass = cJSON_PrintUnformatted(json);
    printf("建群%s\n", pass);
    add_file_size(sockfd, pass);
    cJSON_Delete(json);
}
/*添加群成员*/ //拉好友进群
void add_group_member(int sockfd, int uid)
{
    cJSON *json = cJSON_CreateObject();
    cJSON_AddNumberToObject(json, "signal", ADD_MEMBER);
    printf("please enter the id of your friend\n");
    scanf("%d", &uid);
    cJSON_AddNumberToObject(json, "id", uid);
    char *pass = cJSON_PrintUnformatted(json);
    add_file_size(sockfd, pass);
    cJSON_Delete(json);
}
/*删除群成员*/
void quit_group(int sockfd, int uid)
{
    cJSON *json = cJSON_CreateObject();
    cJSON_AddNumberToObject(json, "signal", QUIT_GROUP);
    cJSON_AddNumberToObject(json, "uid", uid);
    int gid;
    printf("please enter the id of your group\n");
    scanf("%d", &gid);
    cJSON_AddNumberToObject(json, "gid", gid);
    char *pass = cJSON_PrintUnformatted(json);
    add_file_size(sockfd, pass);
    cJSON_Delete(json);
}
/*退群*/
void quit_group_t(int sockfd, int uid)
{
    cJSON *json = cJSON_CreateObject();
    cJSON_AddNumberToObject(json, "signal", QUIT_GROUP_T);
    cJSON_AddNumberToObject(json, "uid", uid);
    int gid;
    printf("please enter the id of your group\n");
    scanf("%d", &gid);
    cJSON_AddNumberToObject(json, "gid", gid);
    char *pass = cJSON_PrintUnformatted(json);
    add_file_size(sockfd, pass);
    cJSON_Delete(json);
}
/*分析ＪＳＯＮ数组*/
void analysis_array(int sockfd)
{
    cJSON *node = analysis_package(sockfd);
    cJSON *tnode = cJSON_GetObjectItem(node, "member");
    cJSON *root = NULL;
    if (tnode->type == cJSON_Array)
    {
        cJSON_ArrayForEach(root, tnode) if (root->type == cJSON_Number)
            printf("%d\t", root->valueint);
    }
    printf("\n");
}
/*私聊*/
void chat_private(int sockfd, int id)
{
    char msg[1024];
    int pid;
    int count = 0;
    // get_friend_list(sockfd);
    while (1)
    {
        cJSON *json = cJSON_CreateObject();
        cJSON_AddNumberToObject(json, "signal", CHAT_PRI);
        cJSON_AddNumberToObject(json, "send_fd", id);
        if (count == 0)
        {
            printf("please enter the id that you want to chat\n");
            scanf("%d", &pid);
        }
        cJSON_AddNumberToObject(json, "recv_fd", pid);
        if (count == 0)
            printf("please enter the msg\n");
        scanf("%s", msg);
        cJSON_AddStringToObject(json, "content", msg);
        char *pass = cJSON_PrintUnformatted(json);
       // printf("bbb%s\n", pass);
        add_file_size(sockfd, pass);
        cJSON_Delete(json);
        if (strcmp(msg, "bye") == 0)
            break;
        count++;
    }
}
/*群聊*/
void chat_group(int sockfd, int uid)
{
    int gid;
    int count = 0;
    while (1)
    {
        cJSON *json = cJSON_CreateObject();
        cJSON_AddNumberToObject(json, "signal", CHAT_GROUP);
        cJSON_AddNumberToObject(json, "uid", uid);
        if (count == 0)
        {
            printf("please enter the group order\n");
            scanf("%d", &gid);
        }
        cJSON_AddNumberToObject(json, "gid", gid);
        char buf[30];
        printf("please enter the content\n");
        scanf("%s", buf);
        cJSON_AddStringToObject(json, "content", buf);
        count++;
        char *pass = cJSON_PrintUnformatted(json);
        cJSON_Delete(json);
        printf("chat_group:%s\n", pass);
        add_file_size(sockfd, pass);
        if (strcmp(buf, "bye") == 0)
            break;
    }
}
/*如果是管理员则禁言某人，否则返回错误信息*/
void group_set_no_speaking(int sockfd, int uid)
{
    cJSON *json = cJSON_CreateObject();
    cJSON_AddNumberToObject(json, "signal", NO_SPEAKING);
    printf("请输入要禁言人的id\n");
    int id;
    scanf("%d", &id);
    cJSON_AddNumberToObject(json, "id", uid);
    cJSON_AddNumberToObject(json, "uid", id);
    printf("请输入组账号\n");
    int gid;
    scanf("%d", &gid);
    cJSON_AddNumberToObject(json, "gid", gid);
    char *pass = cJSON_PrintUnformatted(json);
    add_file_size(sockfd, pass);
    cJSON_Delete(json);
}
/*解除禁言*/
void group_cancle_no_speaking(int sockfd, int uid)
{
    cJSON *json = cJSON_CreateObject();
    cJSON_AddNumberToObject(json, "signal", SPEAKING);
    cJSON_AddNumberToObject(json, "id", uid);
    printf("请输入对方id\n");
    int id;
    scanf("%d", &id);
    cJSON_AddNumberToObject(json, "uid", id);
    printf("please enter the group id\n");
    int gid;
    scanf("%d", &gid);
    cJSON_AddNumberToObject(json, "gid", gid);
    char *pass = cJSON_PrintUnformatted(json);
    add_file_size(sockfd, pass);
    cJSON_Delete(json);
}
/*加群*/
void add_group(int sockfd, int uid)
{
    cJSON *json = cJSON_CreateObject();
    cJSON_AddNumberToObject(json, "signal", ADD_GROUP);
    cJSON_AddNumberToObject(json, "uid", uid);
    int gid;
    printf("please enter the gid\n");
    scanf("%d", &gid);
    char buf[30];
    printf("please enter the group name\n");
    scanf("%s", buf);
    cJSON_AddNumberToObject(json, "gid", gid);
    cJSON_AddStringToObject(json, "name", buf);
    char *pass = cJSON_PrintUnformatted(json);
    add_file_size(sockfd, pass);
    cJSON_Delete(json);
}
/*上传文件*/
int get_file_size(char *filename)
{
    struct stat statbuf;
    stat(filename, &statbuf);
    int size = statbuf.st_size;
    return size;
}
/*void send_file_apply(int uid, int sockfd)
{
    cJSON *json = cJSON_CreateObject();
    cJSON_AddNumberToObject(json, "signal", SEND_FILE_RPLY);
    int fid;
    printf("please enter the friend id\n");
    scanf("%d", &fid);
    cJSON_AddNumberToObject(json, "fid", fid);
    char *pass = cJSON_PrintUnformatted(json);
    add_file_size(sockfd, pass);
    cJSON_Delete(json);
}*/
void send_file(int sockfd, int uid)
{
    int fd;
    char filename[40], buf[900] = {0}, temp[1500] = {0};
    int fid, size;
    printf("please enter the id tha you want to put\n");
    scanf("%d", &fid);
    printf("请输入文件路径\n");
    scanf("%s", filename);
    if ((fd = open(filename, O_RDONLY)) == -1)
    {
        printf("文件打开失败\n");
        return;
    }
    while (1)
    {
        memset(buf, 0, sizeof(buf));
        size = read(fd, buf, sizeof(buf));
        //  lseek(fd,size,SEEK_CUR);
        base64_encode((const unsigned char *)buf, temp, size);
        cJSON *json = cJSON_CreateObject();
        cJSON_AddNumberToObject(json, "signal", SEND_FILE);
        cJSON_AddNumberToObject(json, "send_id", uid);
        cJSON_AddNumberToObject(json, "fid", fid);
        cJSON_AddNumberToObject(json, "f_size", size);
        cJSON_AddStringToObject(json, "filename", filename);
        cJSON_AddStringToObject(json, "base", temp);
        char *pass = cJSON_PrintUnformatted(json);
        printf("pass%d\n", strlen(pass));
        cJSON_Delete(json);
        usleep(7000);
        add_file_size(sockfd, pass);
        printf("文件发送成功\n");
        if (size < (int)sizeof(buf))
            break;
    }
    printf("文件发送成功\n");
    close(fd);
    return;
}
/*收文件函数*/
void recv_file(cJSON *node)
{
    printf("file___==\n");
    int fp = open("tmp", O_CREAT | O_RDWR | O_APPEND, 0777);
    if (fp == -1)
        printf("创建文件失败\n");
    char filename[1024], buf[1500] = {0}, temp[900] = {0};
    int fid;
    int size;
    bzero(&buf, sizeof(buf));
    strcat(buf, cJSON_GetObjectItem(node, "base")->valuestring);
    size = cJSON_GetObjectItem(node, "f_size")->valueint;
    printf("===<<<>>>\n");
    //解码
    base64_decode(buf, (unsigned char *)temp);
    write(fp, temp, size);
    close(fp);
    return;
}
/*查看私聊记录*/
void look_private(int sockfd, int id)
{
    cJSON *json = cJSON_CreateObject();
    printf("请输入朋友id\n");
    int pid;
    scanf("%d", &pid);
    cJSON_AddNumberToObject(json, "signal", LOOK_PRIVATE);
    cJSON_AddNumberToObject(json, "send_id", id);
    cJSON_AddNumberToObject(json, "recv_id", pid);
    char *pass = cJSON_PrintUnformatted(json);
    add_file_size(sockfd, pass);
    cJSON_Delete(json);
}
/*查看群聊记录*/
void record_group_look(int sockfd, int id)
{
    cJSON *json = cJSON_CreateObject();
    printf("请输入组id\n");
    int gid;
    scanf("%d", &gid);
    cJSON_AddNumberToObject(json, "signal", LOOK_GROUP);
    cJSON_AddNumberToObject(json, "gid", gid);
    cJSON_AddNumberToObject(json, "uid", id);
    char *pass = cJSON_PrintUnformatted(json);
    add_file_size(sockfd, pass);
    cJSON_Delete(json);
}
/*菜单选择函数*/
void menu_select(int sockfd, int id)
{
    pthread_t thid1, thid2;
    while (1)
    {
        printf("\n");
        printf("\033[1m\033[;34m\t\t\t=============||好友管理||================\t\t\t\033[0m\n");
        printf("\033[1m\033[;31m\t\t\t*********1.删除好友 2.添加好友********\t\t\t\033[0m\n");
        printf("\033[1m\033[;32m\t\t\t*********3.回复好友 4.获取好友列表*****\t\t\t\033[0m\n");
        printf("\033[1m\033[;33m\t\t\t*********5.私聊     16.私聊记录*****\t\t\t\033[0m\n");
        printf("\033[1m\033[;34m\t\t\t=============||群管理||==================\t\t\t\033[0m\n");       
        printf("\033[1m\033[;35m\t\t\t*********6.创群     7.群聊***********\t\t\t\033[0m\n");
        printf("\033[1m\033[;36m\t\t\t*********8.禁言     9.解除禁言********\t\t\t\033[0m\n");
        printf("\033[1m\033[;38m\t\t\t*********10.获得群好友列表************\t\t\t\033[0m\n");
        printf("\033[1m\033[;38m\t\t\t*********11.获得用户所在群列表*********\t\t\t\033[0m\n");
        printf("\033[1m\033[;39m\t\t\t*********12.删除群成员 13.退群*********\t\t\t\033[0m\n");
        printf("\033[1m\033[;39m\t\t\t*********14.加群  17.查看群聊记录*********\t\t\t\033[0m\n");
        printf("\033[1m\033[;31m\t\t\t*********15.上传文件          *********\t\t\t\033[0m\n");
        printf("\033[1m\033[;33m\t\t\t*********18.退出*****\t\t\t\033[0m\n");
        int choice;
        printf("\t\t\t请输入你的选择:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            delete_usr(sockfd);
            break;
        case 2:
            add_friends(sockfd, id);
            break;
        case 3:
            add_friends_reply(sockfd, friend);
            break;
        case 4:
            get_friend_list(sockfd, id);
            break;
        case 5:
            chat_private(sockfd, id);
            break;
        case 6:
            create_group(sockfd, id);
            break;
        case 7:
            chat_group(sockfd, id);
            break;
        case 8:
            group_set_no_speaking(sockfd, id);
            break;
        case 9:
            group_cancle_no_speaking(sockfd, id);
            break;
        case 10:
            get_group_list(sockfd, id);
            break;
        case 11:
            group_usr_list(sockfd, id);
            break;
        case 12:
            quit_group(sockfd, id);
            break;
        case 13:
            quit_group_t(sockfd, id);
            break;
        case 14:
            add_group(sockfd, id);
            break;
        case 15:
            send_file(sockfd, id);
            break;
        case 16:
            look_private(sockfd, id);
            break;
        case 17:
            record_group_look(sockfd, id);
            break;
        case 18:
            printf("退出中，请稍后......\n");
            sleep(4);
            exit(0);
            break;
        default:
            printf("输入错误，请重新输入\n");
            break;
        }
    }
}
/*二十一世纪得分包函数*/
void *analysis_pack(void *arg)
{
    while (1)
    {
        int sockfd = *(int *)arg;
        int number;
        int recv_num = 0;
        int num_sum = 4;
        while (1)
        {
            if (recv_num == 4)
            {
                printf("goto ok!\n");
                break;
            }
            int aaaaa = recv(sockfd, (char *)&number + recv_num, num_sum, 0);
            recv_num += aaaaa;
            num_sum = 4 - recv_num;
        }
        char *temp = (char *)calloc(sizeof(char) * number + 1, 1);
        int sf, c1 = 0, c2 = 0, c3 = 0;
        int recv_nums = 0;
        while (1)
        {
            if (number == 0)
            {
                break;
            }
            int aaa1 = recv(sockfd, temp + recv_nums, number, 0);
            number -= aaa1;
            recv_nums += aaa1;
        }
        if (/*(sf = recv(sockfd, temp, number, 0)) > 0*/ 1)
        {
            cJSON *node = cJSON_Parse(temp);
            int item = cJSON_GetObjectItem(node, "signal")->valueint;
            int choice;
            switch (item)
            {
            case CHAT_PRI:
                printf("==>>私聊模式\n");
                printf("\033[1m\033[40;33m%d 发来一条消息\033[0m\t", cJSON_GetObjectItem(node, "send_fd")->valueint);
                printf("\033[1m\033[40;33m%s\033[0m\n", cJSON_GetObjectItem(node, "content")->valuestring);
                break;
            case DELETE_FRIEND:
                printf("\033[1m\033[40;30m删除成功\033[0m\n");
                break;
            case ADD_USR:
                printf("\033[1m\033[40;31m成功添加\033[0m\n");
                break;
            case ADD_FRIEND:
                strcpy(friend, temp);
                printf("\033[1m\033[40;31m%s\033[0m", friend);
                printf("\033[1m\033[40;31m请求添加为好友\033[0m\n");
                break;
            case FRIEND_REPLY:
                if (cJSON_GetObjectItem(node, "tip")->valueint == AGREE)
                    printf("\033[1m\033[40;31m对方已成功添加为好友\033[0m\n");
                break;
            case CHAT_GROUP:
                printf("==>>群聊模式\n");
                printf("\033[1m\033[40;33m%d 发来一条消息\033[0m\t", cJSON_GetObjectItem(node, "uid")->valueint);                
                printf("\033[1m\033[40;32m%s\033[0m\n", cJSON_GetObjectItem(node, "content")->valuestring);
                break;
            case SPEAKING:
                printf("\033[1m\033[40;34m%s已被解除禁言\033[0m\n", cJSON_GetObjectItem(node, "content")->valuestring);
                break;
            case NO_SPEAKING:
                printf("\033[1m\033[40;34m%d您已被禁言\033[0m\n", cJSON_GetObjectItem(node, "content")->valuestring);
                break;
            case CREAT_GROUP:
                printf("\033[1m\033[40;35m创群成功\033[0m\n");
                break;
            case GET_FRI_LIST:
                if (c1 == 0)
                    printf("\npid\tstatus\n");
                printf("%d\t%d\n", cJSON_GetObjectItem(node, "pid")->valueint, cJSON_GetObjectItem(node, "status")->valueint);
                c1++;
                break;
            case GET_GROUP_LIST:
                if (c2 == 0)
                    printf("\nuid\t");
                printf("%d\n", cJSON_GetObjectItem(node, "id")->valueint);
                c2++;
                break;
            case GROUP_USR_LST:
                if (c3 == 0)
                    printf("\n%s\t%d\n", cJSON_GetObjectItem(node, "name")->valuestring,
                           cJSON_GetObjectItem(node, "gid")->valueint);
                c3++;
                break;
            case QUIT_GROUP:
                printf("\033[1m\033[40;36m删除成功\033[0m\n");
                break;
            case QUIT_GROUP_T:
                printf("\033[1m\033[40;37m退群成功\033[0m\n");
                break;
            case ADD_GROUP:
                printf("\033[1m\033[40;38m加群成功\033[0m\n");
                break;
            case REGISTER:
                printf("\033[1m\033[40;39m%s\033[0m\n", cJSON_GetObjectItem(node, "content")->valuestring);
                break;
            case LOGIN:
                flag = 1;
                printf("\033[1m\033[40;30m%s\033[0m\n", cJSON_GetObjectItem(node, "content")->valuestring);
                break;
            case SEND_FILE:
                printf("\033[1m\033[40;31m文件请在本地查看\033[0m\n");
                recv_file(node);
                break;
            case WRONG_CODE:
                printf("%s\n", cJSON_GetObjectItem(node, "content")->valuestring);
                printf("\t请重新登录\n");
                break;
            case LOOK_PRIVATE:
                printf("\n%s\n", cJSON_GetObjectItem(node, "content")->valuestring);
                break;
            case LOOK_GROUP:
                printf("\n发送人:\t内容:\t时间\n");
                printf("\n%d\t%s\t%s\n", cJSON_GetObjectItem(node, "send_id")->valueint,
                       cJSON_GetObjectItem(node, "content")->valuestring,
                       cJSON_GetObjectItem(node, "time")->valuestring);
                break;
            default:
                printf("好戏即将开始\n");
                break;
            }
            cJSON_Delete(node);
        }
        free(temp);
    }
}
/*登录函数*/
void login(int sockfd)
{
    int id, i;
    char passwd[10];
    cJSON *json = cJSON_CreateObject();
    cJSON_AddNumberToObject(json, "signal", LOGIN);
    printf("please enter your id codes\n");
    scanf("%d", &id);
    uid = id;
    cJSON_AddNumberToObject(json, "id", id);
    printf("please enter the name\n");
    char name[15];
    scanf("%s", name);
    cJSON_AddStringToObject(json, "name", name);
    printf("please enter the passwd\n");
    while (getchar() != '\n') //又是一个坑ｓｃａｎｆ为什么会有这么多的坑
        continue;
    for (i = 0; i < 8; i++)
        passwd[i] = getch();
    passwd[i] = '\0';
    cJSON_AddStringToObject(json, "passwd", passwd);
    char *pass = cJSON_PrintUnformatted(json);
    printf("%s\n", pass);
    add_file_size(sockfd, pass);
    cJSON_Delete(json);
    return;
}
/*主菜单*/
void menu_main(int sockfd)
{
    int i = 0;
    printf("\t\t\t*********1.login*************\t\t\t\n");
    printf("\t\t\t*********2.register**********\t\t\t\n");
    printf("\t\t\t*********3.back_passwd*******\t\t\t\n");
    printf("\t\t\t*********4.exit**************\t\t\t\n");
    int choice;
    printf("\t\t\t请输入你的选择:");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        login(sockfd);
        break;
    case 2:
        reg(sockfd);
        break;
    case 3:
        back_passwd(sockfd);
        break;
    case 4:
        printf("退出中，请稍后......\n");
        sleep(4);
        exit(0);
        break;
    default:
        printf("输入错误，请重新输入\n");
        exit(1);
        break;
    }
}
int main(int argc, char *argv[])
{
    char *p = "127.0.0.1";
    struct sockaddr_in sever_addr;
    pthread_mutex_init(&mutex, NULL);
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("创建套接字失败\n");
        exit(1);
    }
    bzero(&sever_addr, sizeof(struct sockaddr_in));
    sever_addr.sin_family = AF_INET;
    sever_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, p, &sever_addr.sin_addr);
    int ret = connect(sockfd, (struct sockaddr *)&sever_addr, sizeof(sever_addr));
    if (ret == -1)
    {
        printf("连接失败\n");
        exit(1);
    }
    pthread_t thid1;
    pthread_create(&thid1, NULL, analysis_pack, (void *)&sockfd);
    while (1)
    {
        menu_main(sockfd);
        usleep(1000000);
        printf("%d\n", flag);
        if (flag == 1)
            break;
    }
    while (1)
        menu_select(sockfd, uid);
    return 0;
}