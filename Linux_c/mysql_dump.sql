-- MySQL dump 10.13  Distrib 5.7.18, for Linux (x86_64)
--
-- Host: localhost    Database: chat_room
-- ------------------------------------------------------
-- Server version	5.7.18-1

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
INSERT INTO `friend_info` VALUES (2,2,-1);
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
INSERT INTO `group_info` VALUES (1,'a1',0,110,1),(1,'cd',0,110,2);
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
  `status` int(2) DEFAULT NULL,
  PRIMARY KEY (`gid`,`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `record_group`
--

LOCK TABLES `record_group` WRITE;
/*!40000 ALTER TABLE `record_group` DISABLE KEYS */;
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
  `msg` varchar(200) DEFAULT NULL,
  `status` int(2) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `record_private`
--

LOCK TABLES `record_private` WRITE;
/*!40000 ALTER TABLE `record_private` DISABLE KEYS */;
INSERT INTO `record_private` VALUES (2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"hello\",\"time\":\"Fri Aug 24 18:00:19 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"bye\",\"time\":\"Fri Aug 24 18:00:45 2018\"}',1),(2,2,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":2,\"content\":\"hello\",\"time\":\"Fri Aug 24 18:00:55 2018\"}',1),(2,2,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":2,\"content\":\"bye\",\"time\":\"Fri Aug 24 18:01:16 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"hello\",\"time\":\"Fri Aug 24 18:01:38 2018\"}',1),(1,1,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":1,\"content\":\"hello\",\"time\":\"Fri Aug 24 19:43:53 2018\"}',1),(1,1,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":1,\"content\":\"0\",\"time\":\"Fri Aug 24 19:44:02 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"hello\",\"time\":\"Fri Aug 24 19:45:02 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"why\",\"time\":\"Fri Aug 24 19:45:25 2018\"}',1),(1,1,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":1,\"content\":\"bye\",\"time\":\"Fri Aug 24 19:45:35 2018\"}',1),(1,2,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":2,\"content\":\"hello\",\"time\":\"Fri Aug 24 20:54:36 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"HELLO\",\"time\":\"Fri Aug 24 20:55:21 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"hello\",\"time\":\"Fri Aug 24 20:55:33 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"good\",\"time\":\"Fri Aug 24 20:55:35 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"hello\",\"time\":\"Fri Aug 24 20:56:29 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"good\",\"time\":\"Fri Aug 24 20:56:44 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"hello\",\"time\":\"Fri Aug 24 20:59:06 2018\"}',1),(2,2,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":2,\"content\":\"hello\",\"time\":\"Fri Aug 24 20:59:34 2018\"}',1),(2,2,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":2,\"content\":\"goof\",\"time\":\"Fri Aug 24 20:59:41 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"hello\",\"time\":\"Fri Aug 24 21:12:02 2018\"}',1),(1,2,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":2,\"content\":\"good\",\"time\":\"Fri Aug 24 21:12:27 2018\"}',1),(1,2,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":2,\"content\":\"hello\",\"time\":\"Fri Aug 24 21:13:11 2018\"}',1),(1,2,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":2,\"content\":\"bye\",\"time\":\"Fri Aug 24 21:13:22 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"bye\",\"time\":\"Fri Aug 24 21:13:34 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"hello\",\"time\":\"Fri Aug 24 21:13:40 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"hello\",\"time\":\"Fri Aug 24 21:14:25 2018\"}',1),(1,5,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":5,\"content\":\"foof\",\"time\":\"Fri Aug 24 21:14:47 2018\"}',1),(1,2,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":2,\"content\":\"hello\",\"time\":\"Fri Aug 24 21:25:33 2018\"}',1),(1,2,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":2,\"content\":\"good\",\"time\":\"Fri Aug 24 21:25:43 2018\"}',1),(1,2,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":2,\"content\":\"why\",\"time\":\"Fri Aug 24 21:25:50 2018\"}',1),(1,2,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":2,\"content\":\"14\",\"time\":\"Fri Aug 24 21:26:04 2018\"}',1),(1,2,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":2,\"content\":\"bye\",\"time\":\"Fri Aug 24 21:26:07 2018\"}',1),(1,1,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":1,\"content\":\"hello\",\"time\":\"Fri Aug 24 23:52:33 2018\"}',1),(2,2,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":2,\"content\":\"hello\",\"time\":\"Fri Aug 24 23:52:53 2018\"}',1),(2,2,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":2,\"content\":\"good\",\"time\":\"Fri Aug 24 23:53:22 2018\"}',1),(1,1,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":1,\"content\":\"good\",\"time\":\"Fri Aug 24 23:53:32 2018\"}',1),(2,2,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":2,\"content\":\"why\",\"time\":\"Fri Aug 24 23:53:45 2018\"}',1),(1,1,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":1,\"content\":\"no\",\"time\":\"Fri Aug 24 23:53:53 2018\"}',1),(1,1,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":1,\"content\":\"bye\",\"time\":\"Fri Aug 24 23:54:05 2018\"}',1),(1,2,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":2,\"content\":\"hello\",\"time\":\"Fri Aug 24 23:54:13 2018\"}',1),(2,2,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":2,\"content\":\"bye\",\"time\":\"Fri Aug 24 23:54:21 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"good\",\"time\":\"Fri Aug 24 23:54:34 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"bye\",\"time\":\"Fri Aug 24 23:54:44 2018\"}',1),(1,2,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":2,\"content\":\"hello\",\"time\":\"Sat Aug 25 00:06:51 2018\"}',1),(2,2,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":2,\"content\":\"hello\",\"time\":\"Sat Aug 25 00:08:16 2018\"}',1),(2,2,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":2,\"content\":\"bye\",\"time\":\"Sat Aug 25 00:08:30 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"hello\",\"time\":\"Sat Aug 25 00:08:36 2018\"}',1),(1,2,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":2,\"content\":\"bye\",\"time\":\"Sat Aug 25 00:08:47 2018\"}',1),(1,1,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":1,\"content\":\"hello\",\"time\":\"Sat Aug 25 00:08:57 2018\"}',1),(1,1,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":1,\"content\":\"good\",\"time\":\"Sat Aug 25 00:09:13 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"7\",\"time\":\"Sat Aug 25 00:09:57 2018\"}',1),(1,1,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":1,\"content\":\"5\",\"time\":\"Sat Aug 25 00:10:29 2018\"}',1),(1,1,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":1,\"content\":\"bye\",\"time\":\"Sat Aug 25 00:10:33 2018\"}',1),(1,2,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":2,\"content\":\"hello\",\"time\":\"Sat Aug 25 00:10:46 2018\"}',1),(1,2,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":2,\"content\":\"hello\",\"time\":\"Sat Aug 25 00:14:26 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"hello\",\"time\":\"Sat Aug 25 00:15:35 2018\"}',1),(1,2,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":2,\"content\":\"10\",\"time\":\"Sat Aug 25 00:15:51 2018\"}',1),(1,2,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":2,\"content\":\"bye\",\"time\":\"Sat Aug 25 00:16:11 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"bye\",\"time\":\"Sat Aug 25 00:18:03 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"hello\",\"time\":\"Sat Aug 25 01:57:07 2018\"}',1),(1,2,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":2,\"content\":\"good\",\"time\":\"Sat Aug 25 01:57:24 2018\"}',1),(1,2,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":2,\"content\":\"bye\",\"time\":\"Sat Aug 25 01:57:34 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"bye\",\"time\":\"Sat Aug 25 01:57:38 2018\"}',1),(1,2,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":2,\"content\":\"hello\",\"time\":\"Sat Aug 25 02:45:14 2018\"}',1),(1,2,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":2,\"content\":\"1\",\"time\":\"Sat Aug 25 02:45:52 2018\"}',1),(1,2,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":2,\"content\":\"12\",\"time\":\"Sat Aug 25 02:45:53 2018\"}',1),(1,2,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":2,\"content\":\"e2\",\"time\":\"Sat Aug 25 02:45:56 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"hello\",\"time\":\"Sat Aug 25 02:53:42 2018\"}',1),(1,2,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":2,\"content\":\"hello\",\"time\":\"Sat Aug 25 02:54:04 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"bye\",\"time\":\"Sat Aug 25 02:54:21 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"hello\",\"time\":\"Sat Aug 25 02:57:01 2018\"}',1),(1,2,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":2,\"content\":\"hello\",\"time\":\"Sat Aug 25 02:58:03 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"hello\",\"time\":\"Sat Aug 25 02:58:58 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"hello\",\"time\":\"Sat Aug 25 03:03:07 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"HELLO\",\"time\":\"Sat Aug 25 03:07:40 2018\"}',1),(1,2,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":2,\"content\":\"hello\",\"time\":\"Sat Aug 25 03:11:10 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"hello\",\"time\":\"Sat Aug 25 03:17:05 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"hello\",\"time\":\"Sat Aug 25 03:20:32 2018\"}',1),(1,1,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":1,\"content\":\"hello\",\"time\":\"Sat Aug 25 03:23:24 2018\"}',1),(1,1,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":1,\"content\":\"bye\",\"time\":\"Sat Aug 25 03:23:41 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"hello\",\"time\":\"Sat Aug 25 03:24:01 2018\"}',1),(1,2,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":2,\"content\":\"hello\",\"time\":\"Sat Aug 25 03:24:14 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"hello\",\"time\":\"Sat Aug 25 03:25:40 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"bye\",\"time\":\"Sat Aug 25 03:29:26 2018\"}',1),(1,2,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":2,\"content\":\"hello\",\"time\":\"Sat Aug 25 03:31:20 2018\"}',1),(1,2,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":2,\"content\":\"bye\",\"time\":\"Sat Aug 25 03:31:24 2018\"}',1),(1,2,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":2,\"content\":\"hello\",\"time\":\"Sat Aug 25 08:13:52 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"good\",\"time\":\"Sat Aug 25 08:21:53 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"no\",\"time\":\"Sat Aug 25 08:22:04 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"why\",\"time\":\"Sat Aug 25 08:22:16 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"5\",\"time\":\"Sat Aug 25 08:22:25 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"good\",\"time\":\"Sat Aug 25 08:22:48 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"good\",\"time\":\"Sat Aug 25 08:22:54 2018\"}',1),(1,2,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":2,\"content\":\"why\",\"time\":\"Sat Aug 25 08:23:02 2018\"}',1),(1,2,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":2,\"content\":\"5\",\"time\":\"Sat Aug 25 08:23:13 2018\"}',1),(1,2,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":2,\"content\":\"bye\",\"time\":\"Sat Aug 25 08:23:18 2018\"}',1),(1,1,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":1,\"content\":\"hello\",\"time\":\"Sat Aug 25 08:23:32 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"5\",\"time\":\"Sat Aug 25 08:23:45 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"bye\",\"time\":\"Sat Aug 25 08:23:47 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"hello\",\"time\":\"Sat Aug 25 08:24:04 2018\"}',1),(1,2,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":2,\"content\":\"hello\",\"time\":\"Sat Aug 25 08:27:04 2018\"}',1),(1,2,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":2,\"content\":\"dasdasdad\",\"time\":\"Sat Aug 25 08:27:15 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"good\",\"time\":\"Sat Aug 25 08:27:32 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"dwedw\",\"time\":\"Sat Aug 25 08:27:44 2018\"}',1),(1,2,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":2,\"content\":\"bye\",\"time\":\"Sat Aug 25 08:27:51 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"bye\",\"time\":\"Sat Aug 25 08:28:03 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"hello\",\"time\":\"Sat Aug 25 08:30:48 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"saddsa\",\"time\":\"Sat Aug 25 08:30:56 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"bye\",\"time\":\"Sat Aug 25 08:31:07 2018\"}',1),(1,2,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":2,\"content\":\"hello\",\"time\":\"Sat Aug 25 08:31:24 2018\"}',1),(1,2,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":2,\"content\":\"bye\",\"time\":\"Sat Aug 25 08:31:26 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"hekko\",\"time\":\"Sat Aug 25 08:37:26 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"jejeje\",\"time\":\"Sat Aug 25 08:37:28 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"hehaef\",\"time\":\"Sat Aug 25 08:37:47 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"hello\",\"time\":\"Sat Aug 25 08:48:01 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"asdada\",\"time\":\"Sat Aug 25 08:48:09 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"asdadasdasd\",\"time\":\"Sat Aug 25 08:48:11 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"bye\",\"time\":\"Sat Aug 25 08:48:43 2018\"}',1),(572043,2,'{\"signal\":4,\"send_fd\":572043,\"recv_fd\":2,\"content\":\"asfkjas\",\"time\":\"Sat Aug 25 10:34:34 2018\"}',1),(572043,2,'{\"signal\":4,\"send_fd\":572043,\"recv_fd\":2,\"content\":\"jkjkljkljk\",\"time\":\"Sat Aug 25 10:34:46 2018\"}',1),(572043,2,'{\"signal\":4,\"send_fd\":572043,\"recv_fd\":2,\"content\":\"kljkljlkjl\",\"time\":\"Sat Aug 25 10:34:52 2018\"}',1),(572043,2,'{\"signal\":4,\"send_fd\":572043,\"recv_fd\":2,\"content\":\"bye\",\"time\":\"Sat Aug 25 10:34:58 2018\"}',1),(2,572043,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":572043,\"content\":\"hello\",\"time\":\"Sat Aug 25 10:35:59 2018\"}',1),(572043,2,'{\"signal\":4,\"send_fd\":572043,\"recv_fd\":2,\"content\":\"aklfjasf\",\"time\":\"Sat Aug 25 10:36:12 2018\"}',1),(2,572043,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":572043,\"content\":\"good\",\"time\":\"Sat Aug 25 10:36:19 2018\"}',1),(572043,2,'{\"signal\":4,\"send_fd\":572043,\"recv_fd\":2,\"content\":\"asklfjasd\",\"time\":\"Sat Aug 25 10:36:21 2018\"}',1),(2,572043,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":572043,\"content\":\"gook\",\"time\":\"Sat Aug 25 10:36:24 2018\"}',1),(572043,2,'{\"signal\":4,\"send_fd\":572043,\"recv_fd\":2,\"content\":\"asfklasdjfas;lj\",\"time\":\"Sat Aug 25 10:36:29 2018\"}',1),(572043,2,'{\"signal\":4,\"send_fd\":572043,\"recv_fd\":2,\"content\":\"aklfjasdlkfj\",\"time\":\"Sat Aug 25 10:36:32 2018\"}',1),(572043,2,'{\"signal\":4,\"send_fd\":572043,\"recv_fd\":2,\"content\":\"asfasdf\",\"time\":\"Sat Aug 25 10:36:34 2018\"}',1),(572043,2,'{\"signal\":4,\"send_fd\":572043,\"recv_fd\":2,\"content\":\"fasdf\",\"time\":\"Sat Aug 25 10:36:35 2018\"}',1),(572043,2,'{\"signal\":4,\"send_fd\":572043,\"recv_fd\":2,\"content\":\"bye\",\"time\":\"Sat Aug 25 10:36:38 2018\"}',1),(2,572043,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":572043,\"content\":\"bye\",\"time\":\"Sat Aug 25 10:37:37 2018\"}',1),(572043,2,'{\"signal\":4,\"send_fd\":572043,\"recv_fd\":2,\"content\":\"asfasjkfjasfk\",\"time\":\"Sat Aug 25 10:46:46 2018\"}',1),(572043,2,'{\"signal\":4,\"send_fd\":572043,\"recv_fd\":2,\"content\":\"bye\",\"time\":\"Sat Aug 25 10:49:29 2018\"}',1),(12345678,572043,'{\"signal\":4,\"send_fd\":12345678,\"recv_fd\":572043,\"content\":\"hello\",\"time\":\"Sat Aug 25 10:50:16 2018\"}',1),(12345678,572043,'{\"signal\":4,\"send_fd\":12345678,\"recv_fd\":572043,\"content\":\"hello\",\"time\":\"Sat Aug 25 10:51:47 2018\"}',1),(2,12345678,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":12345678,\"content\":\"hello\",\"time\":\"Sat Aug 25 10:52:37 2018\"}',1),(2,12345678,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":12345678,\"content\":\"good\",\"time\":\"Sat Aug 25 10:52:52 2018\"}',1),(2,12345678,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":12345678,\"content\":\"bye\",\"time\":\"Sat Aug 25 10:53:07 2018\"}',1),(2,572043,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":572043,\"content\":\"hello\",\"time\":\"Sat Aug 25 10:53:16 2018\"}',1),(2,572043,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":572043,\"content\":\"bye\",\"time\":\"Sat Aug 25 10:53:42 2018\"}',1),(2,12345678,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":12345678,\"content\":\"hello\",\"time\":\"Sat Aug 25 10:53:50 2018\"}',1),(2,12345678,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":12345678,\"content\":\"goof\",\"time\":\"Sat Aug 25 10:55:11 2018\"}',1),(12345678,572043,'{\"signal\":4,\"send_fd\":12345678,\"recv_fd\":572043,\"content\":\"mjmjmjm\",\"time\":\"Sat Aug 25 10:55:17 2018\"}',1),(12345678,572043,'{\"signal\":4,\"send_fd\":12345678,\"recv_fd\":572043,\"content\":\"bye\",\"time\":\"Sat Aug 25 10:55:24 2018\"}',1),(12345678,2,'{\"signal\":4,\"send_fd\":12345678,\"recv_fd\":2,\"content\":\"hello\",\"time\":\"Sat Aug 25 10:55:31 2018\"}',1),(12345678,2,'{\"signal\":4,\"send_fd\":12345678,\"recv_fd\":2,\"content\":\"hello\",\"time\":\"Sat Aug 25 10:57:41 2018\"}',1),(12345678,2,'{\"signal\":4,\"send_fd\":12345678,\"recv_fd\":2,\"content\":\"asfasfasf\",\"time\":\"Sat Aug 25 10:57:43 2018\"}',1),(12345678,2,'{\"signal\":4,\"send_fd\":12345678,\"recv_fd\":2,\"content\":\"asfasf\",\"time\":\"Sat Aug 25 10:57:44 2018\"}',1),(12345678,2,'{\"signal\":4,\"send_fd\":12345678,\"recv_fd\":2,\"content\":\"afaf\",\"time\":\"Sat Aug 25 10:57:45 2018\"}',1),(12345678,2,'{\"signal\":4,\"send_fd\":12345678,\"recv_fd\":2,\"content\":\"asfaf\",\"time\":\"Sat Aug 25 10:57:46 2018\"}',1),(12345678,2,'{\"signal\":4,\"send_fd\":12345678,\"recv_fd\":2,\"content\":\"asfafasfasf\",\"time\":\"Sat Aug 25 10:57:48 2018\"}',1),(572043,2,'{\"signal\":4,\"send_fd\":572043,\"recv_fd\":2,\"content\":\"asfasdfsd\",\"time\":\"Sat Aug 25 10:57:52 2018\"}',1),(572043,2,'{\"signal\":4,\"send_fd\":572043,\"recv_fd\":2,\"content\":\"afasdfasd\",\"time\":\"Sat Aug 25 10:57:53 2018\"}',1),(572043,2,'{\"signal\":4,\"send_fd\":572043,\"recv_fd\":2,\"content\":\"asdfasdfasd\",\"time\":\"Sat Aug 25 10:57:54 2018\"}',1),(2,572043,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":572043,\"content\":\"hello\",\"time\":\"Sat Aug 25 11:02:48 2018\"}',1),(572043,2,'{\"signal\":4,\"send_fd\":572043,\"recv_fd\":2,\"content\":\"asklfjaslf\",\"time\":\"Sat Aug 25 11:03:03 2018\"}',1),(2,572043,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":572043,\"content\":\"sdafasfa\",\"time\":\"Sat Aug 25 11:03:11 2018\"}',1),(2,572043,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":572043,\"content\":\"asdadasd\",\"time\":\"Sat Aug 25 11:03:12 2018\"}',1),(2,572043,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":572043,\"content\":\"asdada\",\"time\":\"Sat Aug 25 11:03:14 2018\"}',1),(2,572043,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":572043,\"content\":\"asdadads\",\"time\":\"Sat Aug 25 11:03:15 2018\"}',1),(2,572043,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":572043,\"content\":\"asdasdad\",\"time\":\"Sat Aug 25 11:03:17 2018\"}',1),(572043,2,'{\"signal\":4,\"send_fd\":572043,\"recv_fd\":2,\"content\":\"bye\",\"time\":\"Sat Aug 25 11:03:21 2018\"}',1),(2,572043,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":572043,\"content\":\"bye\",\"time\":\"Sat Aug 25 11:05:26 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"hello\",\"time\":\"Sat Aug 25 11:56:37 2018\"}',1),(1,2,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":2,\"content\":\"fook\",\"time\":\"Sat Aug 25 11:56:49 2018\"}',1),(8,2,'{\"signal\":4,\"send_fd\":8,\"recv_fd\":2,\"content\":\"hello\",\"time\":\"Sat Aug 25 11:59:01 2018\"}',1),(8,2,'{\"signal\":4,\"send_fd\":8,\"recv_fd\":2,\"content\":\"hello\",\"time\":\"Sat Aug 25 12:04:17 2018\"}',1),(8,2,'{\"signal\":4,\"send_fd\":8,\"recv_fd\":2,\"content\":\"good\",\"time\":\"Sat Aug 25 12:04:24 2018\"}',1),(8,2,'{\"signal\":4,\"send_fd\":8,\"recv_fd\":2,\"content\":\"bye\",\"time\":\"Sat Aug 25 12:04:37 2018\"}',1),(8,2,'{\"signal\":4,\"send_fd\":8,\"recv_fd\":2,\"content\":\"hello\",\"time\":\"Sat Aug 25 12:10:17 2018\"}',1),(2,8,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":8,\"content\":\"fodoodasd\",\"time\":\"Sat Aug 25 12:10:32 2018\"}',1),(8,2,'{\"signal\":4,\"send_fd\":8,\"recv_fd\":2,\"content\":\"bye\",\"time\":\"Sat Aug 25 12:10:38 2018\"}',1),(2,8,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":8,\"content\":\"bye\",\"time\":\"Sat Aug 25 12:10:42 2018\"}',1),(2,8,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":8,\"content\":\"hello\",\"time\":\"Sat Aug 25 12:10:55 2018\"}',1),(132134,2,'{\"signal\":4,\"send_fd\":132134,\"recv_fd\":2,\"content\":\"nihao\",\"time\":\"Sat Aug 25 12:25:45 2018\"}',1),(132134,2,'{\"signal\":4,\"send_fd\":132134,\"recv_fd\":2,\"content\":\"æˆ‘å«ç¥å‡¯è¿ª\",\"time\":\"Sat Aug 25 12:25:58 2018\"}',1),(132134,2,'{\"signal\":4,\"send_fd\":132134,\"recv_fd\":2,\"content\":\"clear\",\"time\":\"Sat Aug 25 12:26:00 2018\"}',1),(132134,2,'{\"signal\":4,\"send_fd\":132134,\"recv_fd\":2,\"content\":\"safdfasd\",\"time\":\"Sat Aug 25 12:26:02 2018\"}',1),(132134,2,'{\"signal\":4,\"send_fd\":132134,\"recv_fd\":2,\"content\":\"fas\",\"time\":\"Sat Aug 25 12:26:02 2018\"}',1),(132134,2,'{\"signal\":4,\"send_fd\":132134,\"recv_fd\":2,\"content\":\"as\",\"time\":\"Sat Aug 25 12:26:03 2018\"}',1),(132134,2,'{\"signal\":4,\"send_fd\":132134,\"recv_fd\":2,\"content\":\"dg\",\"time\":\"Sat Aug 25 12:26:03 2018\"}',1),(132134,2,'{\"signal\":4,\"send_fd\":132134,\"recv_fd\":2,\"content\":\"asdg\",\"time\":\"Sat Aug 25 12:26:05 2018\"}',1),(132134,2,'{\"signal\":4,\"send_fd\":132134,\"recv_fd\":2,\"content\":\"asd\",\"time\":\"Sat Aug 25 12:26:05 2018\"}',1),(132134,2,'{\"signal\":4,\"send_fd\":132134,\"recv_fd\":2,\"content\":\"g\",\"time\":\"Sat Aug 25 12:26:11 2018\"}',1),(2,132134,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":132134,\"content\":\"hell\",\"time\":\"Sat Aug 25 12:26:22 2018\"}',1),(2,132134,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":132134,\"content\":\"asdasd\",\"time\":\"Sat Aug 25 12:26:23 2018\"}',1),(2,132134,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":132134,\"content\":\"asdasd\",\"time\":\"Sat Aug 25 12:26:24 2018\"}',1),(2,132134,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":132134,\"content\":\"asdasd\",\"time\":\"Sat Aug 25 12:26:25 2018\"}',1),(2,132134,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":132134,\"content\":\"asdad\",\"time\":\"Sat Aug 25 12:26:26 2018\"}',1),(132134,2,'{\"signal\":4,\"send_fd\":132134,\"recv_fd\":2,\"content\":\"nisaf\",\"time\":\"Sat Aug 25 12:32:11 2018\"}',1),(132134,2,'{\"signal\":4,\"send_fd\":132134,\"recv_fd\":2,\"content\":\"sdgfasdg\",\"time\":\"Sat Aug 25 12:32:12 2018\"}',1),(132134,2,'{\"signal\":4,\"send_fd\":132134,\"recv_fd\":2,\"content\":\"sd\",\"time\":\"Sat Aug 25 12:32:12 2018\"}',1),(132134,2,'{\"signal\":4,\"send_fd\":132134,\"recv_fd\":2,\"content\":\"gas\",\"time\":\"Sat Aug 25 12:32:12 2018\"}',1),(132134,2,'{\"signal\":4,\"send_fd\":132134,\"recv_fd\":2,\"content\":\"dgdag\",\"time\":\"Sat Aug 25 12:32:12 2018\"}',1),(132134,2,'{\"signal\":4,\"send_fd\":132134,\"recv_fd\":2,\"content\":\"sdag\",\"time\":\"Sat Aug 25 12:32:13 2018\"}',1),(132134,2,'{\"signal\":4,\"send_fd\":132134,\"recv_fd\":2,\"content\":\"asdg\",\"time\":\"Sat Aug 25 12:32:13 2018\"}',1),(132134,2,'{\"signal\":4,\"send_fd\":132134,\"recv_fd\":2,\"content\":\"fda\",\"time\":\"Sat Aug 25 12:32:13 2018\"}',1),(132134,2,'{\"signal\":4,\"send_fd\":132134,\"recv_fd\":2,\"content\":\"g\",\"time\":\"Sat Aug 25 12:32:13 2018\"}',1),(132134,2,'{\"signal\":4,\"send_fd\":132134,\"recv_fd\":2,\"content\":\"a\",\"time\":\"Sat Aug 25 12:32:13 2018\"}',1),(132134,2,'{\"signal\":4,\"send_fd\":132134,\"recv_fd\":2,\"content\":\"fg\",\"time\":\"Sat Aug 25 12:32:13 2018\"}',1),(132134,2,'{\"signal\":4,\"send_fd\":132134,\"recv_fd\":2,\"content\":\"bye\",\"time\":\"Sat Aug 25 12:32:18 2018\"}',1),(2,132134,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":132134,\"content\":\"hafsdasd\",\"time\":\"Sat Aug 25 12:32:30 2018\"}',1),(2,132134,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":132134,\"content\":\"adad\",\"time\":\"Sat Aug 25 12:32:32 2018\"}',1),(2,132134,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":132134,\"content\":\"aadsd\",\"time\":\"Sat Aug 25 12:32:33 2018\"}',1),(2,132134,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":132134,\"content\":\"adad\",\"time\":\"Sat Aug 25 12:32:34 2018\"}',1),(2,132134,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":132134,\"content\":\"asdad\",\"time\":\"Sat Aug 25 12:32:36 2018\"}',1),(2,132134,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":132134,\"content\":\"heerwef\",\"time\":\"Sat Aug 25 12:33:10 2018\"}',1),(2,132134,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":132134,\"content\":\"wefwef\",\"time\":\"Sat Aug 25 12:33:12 2018\"}',1),(2,132134,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":132134,\"content\":\"wfwef\",\"time\":\"Sat Aug 25 12:33:13 2018\"}',1),(2,132134,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":132134,\"content\":\"wefw\",\"time\":\"Sat Aug 25 12:33:15 2018\"}',1),(2,132134,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":132134,\"content\":\"bye\",\"time\":\"Sat Aug 25 12:33:17 2018\"}',1),(44,10001,'{\"signal\":4,\"send_fd\":44,\"recv_fd\":10001,\"content\":\"asdasd\",\"time\":\"Sat Aug 25 13:48:46 2018\"}',1),(44,10001,'{\"signal\":4,\"send_fd\":44,\"recv_fd\":10001,\"content\":\"asd\",\"time\":\"Sat Aug 25 13:48:48 2018\"}',1),(44,10001,'{\"signal\":4,\"send_fd\":44,\"recv_fd\":10001,\"content\":\"asd\",\"time\":\"Sat Aug 25 13:48:49 2018\"}',1),(44,10001,'{\"signal\":4,\"send_fd\":44,\"recv_fd\":10001,\"content\":\"asd\",\"time\":\"Sat Aug 25 13:48:50 2018\"}',1),(44,10001,'{\"signal\":4,\"send_fd\":44,\"recv_fd\":10001,\"content\":\"asd\",\"time\":\"Sat Aug 25 13:48:50 2018\"}',1),(44,10001,'{\"signal\":4,\"send_fd\":44,\"recv_fd\":10001,\"content\":\"bye\",\"time\":\"Sat Aug 25 13:48:52 2018\"}',1),(44,10001,'{\"signal\":4,\"send_fd\":44,\"recv_fd\":10001,\"content\":\"asdasd\",\"time\":\"Sat Aug 25 13:49:00 2018\"}',1),(44,10001,'{\"signal\":4,\"send_fd\":44,\"recv_fd\":10001,\"content\":\"asd\",\"time\":\"Sat Aug 25 13:49:00 2018\"}',1),(44,10001,'{\"signal\":4,\"send_fd\":44,\"recv_fd\":10001,\"content\":\"asd\",\"time\":\"Sat Aug 25 13:49:01 2018\"}',1),(44,10001,'{\"signal\":4,\"send_fd\":44,\"recv_fd\":10001,\"content\":\"asd\",\"time\":\"Sat Aug 25 13:49:02 2018\"}',1),(1,2,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":2,\"content\":\"hello\",\"time\":\"Sat Aug 25 13:53:51 2018\"}',1),(1,2,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":2,\"content\":\"bye\",\"time\":\"Sat Aug 25 13:54:02 2018\"}',1),(2,114,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":114,\"content\":\"asdadda\",\"time\":\"Sat Aug 25 13:54:25 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"hello\",\"time\":\"Sat Aug 25 14:17:57 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"hello\",\"time\":\"Sat Aug 25 14:44:45 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"adasd\",\"time\":\"Sat Aug 25 14:44:46 2018\"}',1),(1,2,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":2,\"content\":\"hello\",\"time\":\"Sat Aug 25 14:47:08 2018\"}',1),(2,2,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":2,\"content\":\"hello\",\"time\":\"Sat Aug 25 15:27:07 2018\"}',1),(2,2,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":2,\"content\":\"bye\",\"time\":\"Sat Aug 25 15:27:15 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"hello\",\"time\":\"Sat Aug 25 15:27:25 2018\"}',1),(1,1,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":1,\"content\":\"good\",\"time\":\"Sat Aug 25 15:27:39 2018\"}',1),(1,1,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":1,\"content\":\"bye\",\"time\":\"Sat Aug 25 15:27:48 2018\"}',1),(1,1,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":1,\"content\":\"dood\",\"time\":\"Sat Aug 25 15:27:55 2018\"}',1),(1,1,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":1,\"content\":\"bye\",\"time\":\"Sat Aug 25 15:28:01 2018\"}',1),(1,2,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":2,\"content\":\"dads\",\"time\":\"Sat Aug 25 15:28:08 2018\"}',1),(123,1,'{\"signal\":4,\"send_fd\":123,\"recv_fd\":1,\"content\":\"1dsf\",\"time\":\"Sat Aug 25 15:36:00 2018\"}',1),(123,1,'{\"signal\":4,\"send_fd\":123,\"recv_fd\":1,\"content\":\"sdaf\",\"time\":\"Sat Aug 25 15:36:02 2018\"}',1),(123,1,'{\"signal\":4,\"send_fd\":123,\"recv_fd\":1,\"content\":\"gasd\",\"time\":\"Sat Aug 25 15:36:02 2018\"}',1),(123,1,'{\"signal\":4,\"send_fd\":123,\"recv_fd\":1,\"content\":\"gas\",\"time\":\"Sat Aug 25 15:36:03 2018\"}',1),(123,1,'{\"signal\":4,\"send_fd\":123,\"recv_fd\":1,\"content\":\"dg\",\"time\":\"Sat Aug 25 15:36:04 2018\"}',1),(123,1,'{\"signal\":4,\"send_fd\":123,\"recv_fd\":1,\"content\":\"sdgf\",\"time\":\"Sat Aug 25 15:36:05 2018\"}',1),(123,1,'{\"signal\":4,\"send_fd\":123,\"recv_fd\":1,\"content\":\"asdfg\",\"time\":\"Sat Aug 25 15:36:05 2018\"}',1),(123,1,'{\"signal\":4,\"send_fd\":123,\"recv_fd\":1,\"content\":\"sagsd\",\"time\":\"Sat Aug 25 15:36:06 2018\"}',1),(123,1,'{\"signal\":4,\"send_fd\":123,\"recv_fd\":1,\"content\":\"æˆ‘æ—¥ä½ å¦ˆ\",\"time\":\"Sat Aug 25 15:36:12 2018\"}',1),(123,1,'{\"signal\":4,\"send_fd\":123,\"recv_fd\":1,\"content\":\"è‰æ‹Ÿå—\",\"time\":\"Sat Aug 25 15:36:14 2018\"}',1),(123,1,'{\"signal\":4,\"send_fd\":123,\"recv_fd\":1,\"content\":\"æ›¹å°¼çŽ›\",\"time\":\"Sat Aug 25 15:36:19 2018\"}',1),(1,1115,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":1115,\"content\":\"das\",\"time\":\"Sat Aug 25 15:36:25 2018\"}',1),(123,1,'{\"signal\":4,\"send_fd\":123,\"recv_fd\":1,\"content\":\"nihao\",\"time\":\"Sat Aug 25 15:37:33 2018\"}',1),(123,1,'{\"signal\":4,\"send_fd\":123,\"recv_fd\":1,\"content\":\"ä½ å¥½\",\"time\":\"Sat Aug 25 15:37:35 2018\"}',1),(123,1,'{\"signal\":4,\"send_fd\":123,\"recv_fd\":1,\"content\":\"æˆ‘å«ç¥å‡¯è¿ª\",\"time\":\"Sat Aug 25 15:37:37 2018\"}',1),(123,1,'{\"signal\":4,\"send_fd\":123,\"recv_fd\":1,\"content\":\"å¯=å¯ä»¥ä¸\",\"time\":\"Sat Aug 25 15:37:41 2018\"}',1),(1,123,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":123,\"content\":\"asdas\",\"time\":\"Sat Aug 25 15:37:57 2018\"}',1),(1,123,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":123,\"content\":\"asda\",\"time\":\"Sat Aug 25 15:37:59 2018\"}',1),(1,123,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":123,\"content\":\"asdad\",\"time\":\"Sat Aug 25 15:38:00 2018\"}',1),(1,123,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":123,\"content\":\"asda\",\"time\":\"Sat Aug 25 15:38:01 2018\"}',1),(123,1,'{\"signal\":4,\"send_fd\":123,\"recv_fd\":1,\"content\":\"å¯ä»¥å¬\",\"time\":\"Sat Aug 25 15:38:01 2018\"}',1),(1,123,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":123,\"content\":\"asd\",\"time\":\"Sat Aug 25 15:38:01 2018\"}',1),(1,123,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":123,\"content\":\"asdasd\",\"time\":\"Sat Aug 25 15:38:05 2018\"}',1),(123,1,'{\"signal\":4,\"send_fd\":123,\"recv_fd\":1,\"content\":\"å§å§ï¼›lkjjk\",\"time\":\"Sat Aug 25 15:38:06 2018\"}',1),(1,123,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":123,\"content\":\"asdas\",\"time\":\"Sat Aug 25 15:38:06 2018\"}',1),(1,123,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":123,\"content\":\"asda\",\"time\":\"Sat Aug 25 15:38:07 2018\"}',1),(1,123,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":123,\"content\":\"wishisnad\",\"time\":\"Sat Aug 25 15:38:10 2018\"}',1),(123,1,'{\"signal\":4,\"send_fd\":123,\"recv_fd\":1,\"content\":\"ä½ ä»Šæ™šå•¥æ—¶å€™ç°æœº\",\"time\":\"Sat Aug 25 15:38:11 2018\"}',1),(1,123,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":123,\"content\":\"dasd\",\"time\":\"Sat Aug 25 15:38:11 2018\"}',1),(1,123,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":123,\"content\":\"asda\",\"time\":\"Sat Aug 25 15:38:12 2018\"}',1),(1,123,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":123,\"content\":\"ad\",\"time\":\"Sat Aug 25 15:38:12 2018\"}',1),(123,1,'{\"signal\":4,\"send_fd\":123,\"recv_fd\":1,\"content\":\"å›žå®¶\",\"time\":\"Sat Aug 25 15:38:14 2018\"}',1),(123,1,'{\"signal\":4,\"send_fd\":123,\"recv_fd\":1,\"content\":\"æ©ï¼Ÿï¼Ÿï¼Ÿï¼Ÿ\",\"time\":\"Sat Aug 25 15:38:17 2018\"}',1),(1,123,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":123,\"content\":\"huigechuzi\",\"time\":\"Sat Aug 25 15:38:21 2018\"}',1),(1,123,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":123,\"content\":\"adsad\",\"time\":\"Sat Aug 25 15:38:22 2018\"}',1),(1,123,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":123,\"content\":\"asdads\",\"time\":\"Sat Aug 25 15:38:23 2018\"}',1),(123,1,'{\"signal\":4,\"send_fd\":123,\"recv_fd\":1,\"content\":\"èµžç­‰ä¼šå›žå®¶å§a\",\"time\":\"Sat Aug 25 15:38:30 2018\"}',1),(123,1,'{\"signal\":4,\"send_fd\":123,\"recv_fd\":1,\"content\":\"å››ç‚¹\",\"time\":\"Sat Aug 25 15:38:32 2018\"}',1),(123,1,'{\"signal\":4,\"send_fd\":123,\"recv_fd\":1,\"content\":\"å—¯å—¯å—¯å—¯å‘¢å‘¢ï¼Ÿ\",\"time\":\"Sat Aug 25 15:38:36 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"hadasd\",\"time\":\"Sat Aug 25 15:52:32 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"adadada\",\"time\":\"Sat Aug 25 15:52:42 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"adads\",\"time\":\"Sat Aug 25 15:52:42 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"adadad\",\"time\":\"Sat Aug 25 15:52:44 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"adsad\",\"time\":\"Sat Aug 25 15:52:44 2018\"}',1),(2,1,'{\"signal\":4,\"send_fd\":2,\"recv_fd\":1,\"content\":\"adad\",\"time\":\"Sat Aug 25 15:52:45 2018\"}',1),(123,1,'{\"signal\":4,\"send_fd\":123,\"recv_fd\":1,\"content\":\"asdg\",\"time\":\"Sat Aug 25 16:00:11 2018\"}',1),(1,123,'{\"signal\":4,\"send_fd\":1,\"recv_fd\":123,\"content\":\"hello\",\"time\":\"Sat Aug 25 16:03:25 2018\"}',1);
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
INSERT INTO `usr_info` VALUES (1,'cx','12345678',NULL,1,5),(2,'cf','12345678',NULL,1,7),(123,'123','11111111',NULL,1,6);
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

-- Dump completed on 2018-08-28 18:55:23
