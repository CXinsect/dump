#ifndef __STUDENT__H__
#define __STUDENT__H__
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include<sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <mysql/mysql.h>
#include <pthread.h>
#include <sys/epoll.h>
#include "cJSON.h"
#define PORT 8888
#define BACKLOG 20    //监听数目
#define BUF_SIZE 1024 //缓冲区大小
#define NAME_SIZE 50  //名字大小
#define PEOP_NUM 20
#define USR_NUM 20       //在线用户数量
#define ON_LINE 1        //用户在线
#define OUT_LINE 2       //用户离线
#define SEND_LINE 3      //发信息给在线用户
#define CHAT_PRI 4       //标记私聊模式
#define LOGIN 5          //标记登录
#define REGISTER 6       //标记注册
#define GET_GROUP_LIST 7 //获取群成员列表
#define CREAT_GROUP 8    //建群
#define ADD_MEMBER 9     //添加群成员
#define ADD_FRIEND 10
#define AGREE 11
#define DISAGREE 12     // 添加好友
#define FRIEND_REPLY 13 //好友回复
#define NO_SPEAKING 14  //禁言　　　
#define CHAT_GROUP  15   //群聊
#define SEND_FILE 16     //上传文件
#define SPEAKING  17      //解除禁言
#define ROOT      110      //设置管理员
#define ADD_USR   18       //添加用户
#define DELETE_FRIEND 19 //删除好友
#define GET_FRI_LIST 20    //获得好友列表
#define GROUP_USR_LST 21    //获得群列表
#define QUIT_GROUP  22  //删除群成员
#define QUIT_GROUP_T  23   //　退群
#define ADD_GROUP  24     //加群
#define SEND_FILE_RPLY 25 //发文件请求
#define WRONG_CODE 26       //密码问题
#define LOOK_PRIVATE 27    //查看私聊记录
#define LOOK_GROUP 28      // 查看群聊记录
pthread_mutex_t mutex;
/*用户登录信息*/
struct usr_info
{
    int id;
    char usrname[20];
    char passwd[8];
    int root;
    int status;
    int sockfd;
};
struct usr_info usr[USR_NUM];
int usr_number;
int uid;
int path = 1;
int S_sock;
/*数据包信息*/
typedef struct package
{
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
FRIEND_INFO *ff = NULL;
typedef struct group_info
{
    char group_name[NAME_SIZE];
    int group_guys;
    char group_guy_name[PEOP_NUM][NAME_SIZE];
} GROUP_INFO;
typedef struct message
{
    cJSON *node;
    char buf[8000000];
    int fd;
} MSG;
#endif
