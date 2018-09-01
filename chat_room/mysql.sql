-- MySQL dump 10.13  Distrib 5.7.21, for Linux (x86_64)
--
-- Host: localhost    Database: chat_room
-- ------------------------------------------------------
-- Server version	5.7.21-1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `friend_info`
--

DROP TABLE IF EXISTS `friend_info`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `friend_info` (
  `id` int(11) NOT NULL,
  `pid` int(8) DEFAULT NULL,
  `status` int(2) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `friend_info`
--

LOCK TABLES `friend_info` WRITE;
/*!40000 ALTER TABLE `friend_info` DISABLE KEYS */;
INSERT INTO `friend_info` VALUES (2,1,1),(1,2,1),(1,2,1),(2,1,1),(1,2,1),(2,1,1),(2,1,1),(1,2,1),(2,2,1),(2,2,1),(2,3,1),(3,2,1),(3,2,1),(2,3,1),(1,2,1),(2,1,1),(2,1,1),(1,2,1),(6,5,1),(5,6,1);
/*!40000 ALTER TABLE `friend_info` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `group_info`
--

DROP TABLE IF EXISTS `group_info`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `group_info` (
  `gid` int(8) NOT NULL,
  `name` varchar(20) DEFAULT NULL,
  `member` int(8) DEFAULT NULL,
  `root` int(2) DEFAULT NULL,
  `id` int(2) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `group_info`
--

LOCK TABLES `group_info` WRITE;
/*!40000 ALTER TABLE `group_info` DISABLE KEYS */;
INSERT INTO `group_info` VALUES (1,'cx',0,110,1),(1,'cx',17,-1,2),(4,'cf',0,110,5);
/*!40000 ALTER TABLE `group_info` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `group_member`
--

DROP TABLE IF EXISTS `group_member`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `group_member` (
  `gid` int(5) NOT NULL,
  `uid` int(5) DEFAULT NULL,
  `authority` int(5) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `group_member`
--

LOCK TABLES `group_member` WRITE;
/*!40000 ALTER TABLE `group_member` DISABLE KEYS */;
/*!40000 ALTER TABLE `group_member` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `pack_info`
--

DROP TABLE IF EXISTS `pack_info`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `pack_info` (
  `send_name` varchar(20) DEFAULT NULL,
  `recv_name` varchar(20) DEFAULT NULL,
  `send_fd` int(8) DEFAULT NULL,
  `recv_fd` int(8) DEFAULT NULL,
  `time` varchar(20) DEFAULT NULL,
  `content` varchar(100) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `pack_info`
--

LOCK TABLES `pack_info` WRITE;
/*!40000 ALTER TABLE `pack_info` DISABLE KEYS */;
/*!40000 ALTER TABLE `pack_info` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `record_group`
--

DROP TABLE IF EXISTS `record_group`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `record_group` (
  `gid` int(8) NOT NULL,
  `id` int(8) NOT NULL,
  `msg` varchar(200) DEFAULT NULL,
  `time` varchar(40) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `record_group`
--

LOCK TABLES `record_group` WRITE;
/*!40000 ALTER TABLE `record_group` DISABLE KEYS */;
INSERT INTO `record_group` VALUES (1,2,'dasdasda','Sat Sep  1 11:54:13 2018'),(1,2,'asdasd','Sat Sep  1 11:54:14 2018');
/*!40000 ALTER TABLE `record_group` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `record_private`
--

DROP TABLE IF EXISTS `record_private`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `record_private` (
  `sid` int(4) DEFAULT NULL,
  `rid` int(4) DEFAULT NULL,
  `msg` varchar(200) CHARACTER SET utf8 DEFAULT NULL,
  `status` int(2) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `record_private`
--

LOCK TABLES `record_private` WRITE;
/*!40000 ALTER TABLE `record_private` DISABLE KEYS */;
INSERT INTO `record_private` VALUES (2,1,'{\"send_id\":2,\"recv_id\":1,\"time\":\"Fri Aug 31 20:16:04 2018\"}',1),(2,1,'{\"send_id\":2,\"recv_id\":1,\"time\":\"Fri Aug 31 20:16:05 2018\"}',1),(2,1,'{\"send_id\":2,\"recv_id\":1,\"time\":\"Fri Aug 31 20:16:46 2018\"}',1),(1,2,'{\"send_id\":1,\"recv_id\":2,\"time\":\"Fri Aug 31 20:20:38 2018\",\"content\":\"asdasd\"}',1),(1,2,'{\"send_id\":1,\"recv_id\":2,\"time\":\"Fri Aug 31 20:20:39 2018\",\"content\":\"asdasd\"}',1),(1,2,'{\"send_id\":1,\"recv_id\":2,\"time\":\"Fri Aug 31 20:20:39 2018\",\"content\":\"asdasd\"}',1),(1,2,'{\"send_id\":1,\"recv_id\":2,\"time\":\"Fri Aug 31 20:20:57 2018\",\"content\":\"bye\"}',1),(1,2,'{\"send_id\":1,\"recv_id\":2,\"time\":\"Fri Aug 31 22:29:19 2018\",\"content\":\"adsasd\"}',1),(1,2,'{\"send_id\":1,\"recv_id\":2,\"time\":\"Fri Aug 31 22:29:20 2018\",\"content\":\"asdasd\"}',1),(3,2,'{\"send_id\":3,\"recv_id\":2,\"time\":\"Fri Aug 31 22:34:23 2018\",\"content\":\"dasdasd\"}',1),(3,2,'{\"send_id\":3,\"recv_id\":2,\"time\":\"Fri Aug 31 22:34:24 2018\",\"content\":\"asdasd\"}',1),(2,3,'{\"send_id\":2,\"recv_id\":3,\"time\":\"Fri Aug 31 22:34:36 2018\",\"content\":\"asdasd\"}',1),(2,3,'{\"send_id\":2,\"recv_id\":3,\"time\":\"Fri Aug 31 22:34:37 2018\",\"content\":\"asdasd\"}',1),(2,3,'{\"send_id\":2,\"recv_id\":3,\"time\":\"Fri Aug 31 22:34:38 2018\",\"content\":\"asdasd\"}',1),(3,2,'{\"send_id\":3,\"recv_id\":2,\"time\":\"Fri Aug 31 22:35:52 2018\",\"content\":\"bye\"}',1),(2,1,'{\"send_id\":2,\"recv_id\":1,\"time\":\"Fri Aug 31 22:44:29 2018\",\"content\":\"dasdasd\"}',1),(2,1,'{\"send_id\":2,\"recv_id\":1,\"time\":\"Fri Aug 31 22:44:30 2018\",\"content\":\"asdasd\"}',1),(2,1,'{\"send_id\":2,\"recv_id\":1,\"time\":\"Fri Aug 31 22:44:31 2018\",\"content\":\"asdasd\"}',1),(1,2,'{\"send_id\":1,\"recv_id\":2,\"time\":\"Fri Aug 31 22:44:38 2018\",\"content\":\"dasdas\"}',1),(1,2,'{\"send_id\":1,\"recv_id\":2,\"time\":\"Fri Aug 31 22:44:39 2018\",\"content\":\"asdasd\"}',1),(1,2,'{\"send_id\":1,\"recv_id\":2,\"time\":\"Fri Aug 31 22:44:41 2018\",\"content\":\"asdasdasddasd\"}',1),(1,2,'{\"send_id\":1,\"recv_id\":2,\"time\":\"Fri Aug 31 22:45:11 2018\",\"content\":\"2\"}',1),(1,2,'{\"send_id\":1,\"recv_id\":2,\"time\":\"Fri Aug 31 22:45:13 2018\",\"content\":\"bye\"}',1),(2,1,'{\"send_id\":2,\"recv_id\":1,\"time\":\"Fri Aug 31 22:45:23 2018\",\"content\":\"3\"}',1),(2,1,'{\"send_id\":2,\"recv_id\":1,\"time\":\"Fri Aug 31 22:45:27 2018\",\"content\":\"bye\"}',1),(5,6,'{\"send_id\":5,\"recv_id\":6,\"time\":\"Sat Sep  1 10:13:52 2018\",\"content\":\"hello\"}',1),(6,6,'{\"send_id\":6,\"recv_id\":6,\"time\":\"Sat Sep  1 10:14:05 2018\",\"content\":\"good\"}',1),(6,6,'{\"send_id\":6,\"recv_id\":6,\"time\":\"Sat Sep  1 10:14:15 2018\",\"content\":\"bye\"}',1),(6,5,'{\"send_id\":6,\"recv_id\":5,\"time\":\"Sat Sep  1 10:14:21 2018\",\"content\":\"good\"}',1),(5,6,'{\"send_id\":5,\"recv_id\":6,\"time\":\"Sat Sep  1 10:14:27 2018\",\"content\":\"bye\"}',1),(6,5,'{\"send_id\":6,\"recv_id\":5,\"time\":\"Sat Sep  1 10:14:31 2018\",\"content\":\"bye\"}',1);
/*!40000 ALTER TABLE `record_private` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `usr_info`
--

DROP TABLE IF EXISTS `usr_info`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `usr_info` (
  `id` int(11) NOT NULL,
  `name` varchar(20) DEFAULT NULL,
  `passwd` varchar(8) DEFAULT NULL,
  `root` int(2) DEFAULT NULL,
  `status` int(2) DEFAULT NULL,
  `sockfd` int(8) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `usr_info`
--

LOCK TABLES `usr_info` WRITE;
/*!40000 ALTER TABLE `usr_info` DISABLE KEYS */;
INSERT INTO `usr_info` VALUES (1,'cf','12345678',NULL,1,5),(2,'cf','12345678',NULL,1,7),(3,'cf','12345678',NULL,1,5),(5,'cf','12345678',NULL,2,5),(6,'cf','12345678',NULL,2,7);
/*!40000 ALTER TABLE `usr_info` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2018-09-01 12:21:23
