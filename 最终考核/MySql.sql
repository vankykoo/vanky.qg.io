/*
SQLyog Community v13.1.6 (64 bit)
MySQL - 5.7.19 : Database - qg_case
*********************************************************************
*/

/*!40101 SET NAMES utf8 */;

/*!40101 SET SQL_MODE=''*/;

/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;
CREATE DATABASE /*!32312 IF NOT EXISTS*/`qg_case` /*!40100 DEFAULT CHARACTER SET utf8 */;

USE `qg_case`;

/*Table structure for table `tb_application` */

DROP TABLE IF EXISTS `tb_application`;

CREATE TABLE `tb_application` (
  `application_id` int(5) NOT NULL AUTO_INCREMENT,
  `application_picture` varchar(300) DEFAULT NULL,
  `application_description` varchar(100) DEFAULT NULL,
  `application_state` int(5) DEFAULT NULL,
  `user_id` int(11) DEFAULT NULL,
  `application_type` int(5) DEFAULT NULL,
  `user_name` varchar(50) DEFAULT NULL,
  `application_name` varchar(50) DEFAULT NULL,
  `application_date` date DEFAULT NULL,
  `address` varchar(50) DEFAULT NULL,
  `goods_id` int(11) DEFAULT NULL,
  PRIMARY KEY (`application_id`)
) ENGINE=InnoDB AUTO_INCREMENT=31 DEFAULT CHARSET=utf8;

/*Data for the table `tb_application` */

insert  into `tb_application`(`application_id`,`application_picture`,`application_description`,`application_state`,`user_id`,`application_type`,`user_name`,`application_name`,`application_date`,`address`,`goods_id`) values 
(17,'https://img.zcool.cn/community/01ce02556b163f0000009fcbd2431d.jpg@1280w_1l_2o_100sh.jpg','Are you OK?',1,8,1,'Mary','小米官方旗舰店','2023-04-29','北京市朝阳区',NULL),
(18,'https://cdn.cnbj0.fds.api.mi-img.com/b2c-shopapi-pms/pms_1681805071.89555963.png','徕卡光学全焦段四摄| 一英寸可变光圈| 徕卡专业街拍模式| 第二代骁龙8｜2K OLED 屏幕｜50',1,8,2,'Mary','Xiaomi 13 Ultra','2023-04-29','北京市朝阳区',13),
(19,'https://cdn.cnbj0.fds.api.mi-img.com/b2c-shopapi-pms/pms_1670747135.10194785.png','第二代骁龙8｜2K OLED 屏幕 | 徕卡专业光学镜头｜徕卡原生双画质｜徕卡75mm浮动长焦｜12',1,8,2,'Mary','Xiaomi 13 Pro','2023-04-29','北京市朝阳区',14),
(20,'https://cdn.cnbj0.fds.api.mi-img.com/b2c-shopapi-pms/pms_1681707851.39668970.png','11英寸2.8K护眼屏｜骁龙870旗舰处理器｜8840mAh大电量｜MIUI高效办公体验',1,8,2,'Mary','Xiaomi Pad 6','2023-04-29','北京市朝阳区',15),
(21,'https://cdn.cnbj0.fds.api.mi-img.com/b2c-shopapi-pms/pms_1681823435.21188534.jpg','全新自研画质引擎 | 千级分区QD-Mini LED | 2000nits 峰值亮度',1,8,2,'Mary','小米电视大师86英寸Mini LED','2023-04-29','北京市朝阳区',16),
(22,'https://cdn.cnbj0.fds.api.mi-img.com/b2c-shopapi-pms/pms_1681803663.21032834.jpg','多样快拆时尚腕带 | 跑步豆模式 | 体感互动拳击',1,8,2,'Mary','小米手环8','2023-04-29','北京市朝阳区',17),
(23,'https://cdn.cnbj0.fds.api.mi-img.com/b2c-shopapi-pms/pms_1681784907.32679730.jpg','四单元高保真立体声｜哈曼联合调校｜21小时长续航｜IP66防尘防水 ｜音乐互联互通｜小爱同学',1,8,2,'Mary','Xiaomi Sound Move','2023-04-29','北京市朝阳区',18),
(25,'https://static.nike.com.cn/a/images/t_PDP_864_v1/f_auto,b_rgb:f5f5f5/c24ddc33-6e38-4cc9-b548-dc48cd3528ea/alphafly-2-%E7%94%B7%E5%AD%90%E5%85%AC%E8%B7%AF%E7%AB%9E%E9%80%9F%E8%B7%91%E6%AD%A5%E9%9E%8B-F2MZn9.png','男子公路竞速跑步鞋',1,9,2,'Leo',' Nike Alphafly 2 ','2023-04-29','山西省太原市',19),
(26,'https://static.nike.com.cn/a/images/t_PDP_864_v1/f_auto,b_rgb:f5f5f5/1af9c87c-6e11-4bc6-ad66-648558bc49b7/vaporfly-3-%E7%94%B7%E5%AD%90%E5%85%AC%E8%B7%AF%E7%AB%9E%E9%80%9F%E8%B7%91%E6%AD%A5%E9%9E%8B-xjMGJp.png','男子公路竞速跑步鞋',1,9,2,'Leo','Nike Vaporfly 3','2023-04-29','山西省太原市',20),
(27,'https://static.nike.com.cn/a/images/t_PDP_864_v1/f_auto,b_rgb:f5f5f5/d73e1101-a142-4055-84bb-1db91522b10c/vaporfly-2-%E7%94%B7%E5%AD%90%E5%85%A8%E6%8E%8C%E7%A2%B3%E6%9D%BF%E7%AB%9E%E9%80%9F%E8%B7%91%E6%AD%A5%E9%9E%8B-j3lQrg.png','男子全掌碳板竞速跑步鞋',1,9,2,'Leo','Nike Vaporfly 2','2023-04-29','山西省太原市',21),
(28,'https://static1.adidas.com.cn/t395/MTY4MTE5NDE5MTI5MjNkODU1YjAwLTFmNjAtNDQzNy04YzNk.jpg','全速争胜马拉松跑步运动鞋',1,9,2,'Leo','ADIZERO PRIME X STRU','2023-04-29','山西省太原市',22),
(29,'https://static1.adidas.com.cn/t395/MTY3OTI4MTIyNzI2MGU3NWIzZTYyLWIwZDItNDYyYS1hZGVj.jpg','全速争胜马拉松碳柱跑鞋',1,9,2,'Leo','ADIZERO ADIOS PRO 3','2023-04-29','山西省太原市',23),
(30,'https://s7d4.scene7.com/is/image/WolverineWorldWide/S20768-35_1?wid=826&hei=685&resMode=bilin&op_usm=0.5,1.0,8,0&iccEmbed=0&printRes=72','更高更快，95%回弹效果',1,9,2,'Leo','ENDORPHIN ELITE','2023-04-29','山西省太原市',24);

/*Table structure for table `tb_cart` */

DROP TABLE IF EXISTS `tb_cart`;

CREATE TABLE `tb_cart` (
  `user_id` int(11) DEFAULT NULL,
  `goods_id` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `tb_cart` */

insert  into `tb_cart`(`user_id`,`goods_id`) values 
(9,14),
(9,16),
(10,14),
(10,20);

/*Table structure for table `tb_comment` */

DROP TABLE IF EXISTS `tb_comment`;

CREATE TABLE `tb_comment` (
  `goods_id` int(11) DEFAULT NULL,
  `grade` varchar(5) DEFAULT NULL,
  `description` varchar(200) DEFAULT NULL,
  `comment_id` int(11) NOT NULL AUTO_INCREMENT,
  `user_id` int(11) DEFAULT NULL,
  PRIMARY KEY (`comment_id`)
) ENGINE=InnoDB AUTO_INCREMENT=25 DEFAULT CHARSET=utf8;

/*Data for the table `tb_comment` */

insert  into `tb_comment`(`goods_id`,`grade`,`description`,`comment_id`,`user_id`) values 
(23,'5','太好穿了！',24,9);

/*Table structure for table `tb_goods` */

DROP TABLE IF EXISTS `tb_goods`;

CREATE TABLE `tb_goods` (
  `goods_id` int(11) NOT NULL AUTO_INCREMENT,
  `goods_name` varchar(30) DEFAULT NULL,
  `goods_inventory` int(10) DEFAULT NULL,
  `goods_state` int(5) DEFAULT NULL,
  `goods_monthly_sales` int(5) DEFAULT NULL,
  `goods_picture` varchar(300) DEFAULT NULL,
  `goods_store_id` int(11) DEFAULT NULL,
  `goods_description` varchar(100) DEFAULT NULL,
  `goods_price` int(10) DEFAULT NULL,
  PRIMARY KEY (`goods_id`)
) ENGINE=InnoDB AUTO_INCREMENT=25 DEFAULT CHARSET=utf8;

/*Data for the table `tb_goods` */

insert  into `tb_goods`(`goods_id`,`goods_name`,`goods_inventory`,`goods_state`,`goods_monthly_sales`,`goods_picture`,`goods_store_id`,`goods_description`,`goods_price`) values 
(13,'Xiaomi 13 Ultra',998,1,2,'https://cdn.cnbj0.fds.api.mi-img.com/b2c-shopapi-pms/pms_1681805071.89555963.png',5,'徕卡光学全焦段四摄| 一英寸可变光圈| 徕卡专业街拍模式| 第二代骁龙8｜2K OLED 屏幕｜50',5999),
(14,'Xiaomi 13 Pro',2000,1,0,'https://cdn.cnbj0.fds.api.mi-img.com/b2c-shopapi-pms/pms_1670747135.10194785.png',5,'第二代骁龙8｜2K OLED 屏幕 | 徕卡专业光学镜头｜徕卡原生双画质｜徕卡75mm浮动长焦｜12',4999),
(15,'Xiaomi Pad 6',4999,1,1,'https://cdn.cnbj0.fds.api.mi-img.com/b2c-shopapi-pms/pms_1681707851.39668970.png',5,'11英寸2.8K护眼屏｜骁龙870旗舰处理器｜8840mAh大电量｜MIUI高效办公体验',1999),
(16,'小米电视大师86英寸Mini LED',100,1,0,'https://cdn.cnbj0.fds.api.mi-img.com/b2c-shopapi-pms/pms_1681823435.21188534.jpg',5,'全新自研画质引擎 | 千级分区QD-Mini LED | 2000nits 峰值亮度',14999),
(17,'小米手环8',6997,1,0,'https://cdn.cnbj0.fds.api.mi-img.com/b2c-shopapi-pms/pms_1681803663.21032834.jpg',5,'多样快拆时尚腕带 | 跑步豆模式 | 体感互动拳击',199),
(18,'Xiaomi Sound Move',2341,1,0,'https://cdn.cnbj0.fds.api.mi-img.com/b2c-shopapi-pms/pms_1681784907.32679730.jpg',5,'四单元高保真立体声｜哈曼联合调校｜21小时长续航｜IP66防尘防水 ｜音乐互联互通｜小爱同学',699),
(19,' Nike Alphafly 2 ',300,1,0,'https://static.nike.com.cn/a/images/t_PDP_864_v1/f_auto,b_rgb:f5f5f5/c24ddc33-6e38-4cc9-b548-dc48cd3528ea/alphafly-2-%E7%94%B7%E5%AD%90%E5%85%AC%E8%B7%AF%E7%AB%9E%E9%80%9F%E8%B7%91%E6%AD%A5%E9%9E%8B-F2MZn9.png',6,'男子公路竞速跑步鞋',2499),
(20,'Nike Vaporfly 3',4000,1,0,'https://static.nike.com.cn/a/images/t_PDP_864_v1/f_auto,b_rgb:f5f5f5/1af9c87c-6e11-4bc6-ad66-648558bc49b7/vaporfly-3-%E7%94%B7%E5%AD%90%E5%85%AC%E8%B7%AF%E7%AB%9E%E9%80%9F%E8%B7%91%E6%AD%A5%E9%9E%8B-xjMGJp.png',6,'男子公路竞速跑步鞋',1599),
(21,'Nike Vaporfly 2',0,1,0,'https://static.nike.com.cn/a/images/t_PDP_864_v1/f_auto,b_rgb:f5f5f5/d73e1101-a142-4055-84bb-1db91522b10c/vaporfly-2-%E7%94%B7%E5%AD%90%E5%85%A8%E6%8E%8C%E7%A2%B3%E6%9D%BF%E7%AB%9E%E9%80%9F%E8%B7%91%E6%AD%A5%E9%9E%8B-j3lQrg.png',6,'男子全掌碳板竞速跑步鞋',1499),
(22,'ADIZERO PRIME X STRU',1322,2,0,'https://static1.adidas.com.cn/t395/MTY4MTE5NDE5MTI5MjNkODU1YjAwLTFmNjAtNDQzNy04YzNk.jpg',6,'全速争胜马拉松跑步运动鞋',2399),
(23,'ADIZERO ADIOS PRO 3',2310,1,1,'https://static1.adidas.com.cn/t395/MTY3OTI4MTIyNzI2MGU3NWIzZTYyLWIwZDItNDYyYS1hZGVj.jpg',6,'全速争胜马拉松碳柱跑鞋',1999),
(24,'ENDORPHIN ELITE',1231,1,0,'https://s7d4.scene7.com/is/image/WolverineWorldWide/S20768-35_1?wid=826&hei=685&resMode=bilin&op_usm=0.5,1.0,8,0&iccEmbed=0&printRes=72',6,'更高更快，95%回弹效果',2399);

/*Table structure for table `tb_notice` */

DROP TABLE IF EXISTS `tb_notice`;

CREATE TABLE `tb_notice` (
  `notice_time` datetime DEFAULT NULL,
  `notice_content` varchar(50) DEFAULT NULL,
  `notice_getter_id` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `tb_notice` */

insert  into `tb_notice`(`notice_time`,`notice_content`,`notice_getter_id`) values 
('2023-04-29 17:17:26','恭喜你，开店申请已审核通过！',8),
('2023-04-29 17:23:09','恭喜你，上架商品申请已审核通过！',8),
('2023-04-29 17:23:10','恭喜你，上架商品申请已审核通过！',8),
('2023-04-29 17:23:11','恭喜你，上架商品申请已审核通过！',8),
('2023-04-29 17:23:11','恭喜你，上架商品申请已审核通过！',8),
('2023-04-29 17:23:11','恭喜你，上架商品申请已审核通过！',8),
('2023-04-29 17:23:12','恭喜你，上架商品申请已审核通过！',8),
('2023-04-29 17:55:35','恭喜你，开店申请已审核通过！',9),
('2023-04-29 18:06:48','恭喜你，上架商品申请已审核通过！',9),
('2023-04-29 18:06:49','恭喜你，上架商品申请已审核通过！',9),
('2023-04-29 18:06:49','恭喜你，上架商品申请已审核通过！',9),
('2023-04-29 18:06:50','恭喜你，上架商品申请已审核通过！',9),
('2023-04-29 18:06:51','恭喜你，上架商品申请已审核通过！',9),
('2023-04-29 18:06:51','恭喜你，上架商品申请已审核通过！',9);

/*Table structure for table `tb_order` */

DROP TABLE IF EXISTS `tb_order`;

CREATE TABLE `tb_order` (
  `order_id` int(11) NOT NULL AUTO_INCREMENT,
  `order_state` int(5) DEFAULT NULL,
  `customer_place` varchar(50) DEFAULT NULL,
  `store_place` varchar(50) DEFAULT NULL,
  `user_id` int(11) DEFAULT NULL,
  `order_time` datetime DEFAULT NULL,
  `goods_id` int(11) DEFAULT NULL,
  `goods_picture` varchar(300) DEFAULT NULL,
  `goods_name` varchar(50) DEFAULT NULL,
  `goods_store_id` int(11) DEFAULT NULL,
  PRIMARY KEY (`order_id`)
) ENGINE=InnoDB AUTO_INCREMENT=66 DEFAULT CHARSET=utf8;

/*Data for the table `tb_order` */

insert  into `tb_order`(`order_id`,`order_state`,`customer_place`,`store_place`,`user_id`,`order_time`,`goods_id`,`goods_picture`,`goods_name`,`goods_store_id`) values 
(62,1,'广东省河源市','北京市朝阳区',9,'2023-04-29 17:54:26',13,'https://cdn.cnbj0.fds.api.mi-img.com/b2c-shopapi-pms/pms_1681805071.89555963.png','Xiaomi 13 Ultra',5),
(63,1,'广东省河源市','北京市朝阳区',9,'2023-04-29 17:54:47',15,'https://cdn.cnbj0.fds.api.mi-img.com/b2c-shopapi-pms/pms_1681707851.39668970.png','Xiaomi Pad 6',5),
(64,1,'美国洛杉矶','北京市朝阳区',10,'2023-04-29 21:57:29',13,'https://cdn.cnbj0.fds.api.mi-img.com/b2c-shopapi-pms/pms_1681805071.89555963.png','Xiaomi 13 Ultra',5),
(65,5,'广东省河源市','山西省太原市',9,'2023-04-29 22:10:53',23,'https://static1.adidas.com.cn/t395/MTY3OTI4MTIyNzI2MGU3NWIzZTYyLWIwZDItNDYyYS1hZGVj.jpg','ADIZERO ADIOS PRO 3',6);

/*Table structure for table `tb_store` */

DROP TABLE IF EXISTS `tb_store`;

CREATE TABLE `tb_store` (
  `store_id` int(11) NOT NULL AUTO_INCREMENT,
  `store_name` varchar(20) DEFAULT NULL,
  `store_picture` varchar(300) DEFAULT NULL,
  `store_address` varchar(50) DEFAULT NULL,
  `store_user_id` int(11) DEFAULT NULL,
  PRIMARY KEY (`store_id`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8;

/*Data for the table `tb_store` */

insert  into `tb_store`(`store_id`,`store_name`,`store_picture`,`store_address`,`store_user_id`) values 
(5,'小米官方旗舰店','https://img.zcool.cn/community/01ce02556b163f0000009fcbd2431d.jpg@1280w_1l_2o_100sh.jpg','北京市朝阳区',8),
(6,'马拉松运动装备专卖店','https://tse2-mm.cn.bing.net/th/id/OIP-C.oIrr3pt7itnUv9u2IHGNigHaE8?pid=ImgDet&rs=1','山西省太原市',9);

/*Table structure for table `tb_user` */

DROP TABLE IF EXISTS `tb_user`;

CREATE TABLE `tb_user` (
  `user_id` int(11) NOT NULL AUTO_INCREMENT,
  `user_name` varchar(20) DEFAULT NULL,
  `password` varchar(18) DEFAULT NULL,
  `user_picture` varchar(300) DEFAULT NULL,
  `user_address` varchar(50) DEFAULT NULL,
  `phoneNumber` varchar(15) DEFAULT NULL,
  `identity` int(5) DEFAULT NULL,
  `user_store_id` int(11) DEFAULT NULL,
  PRIMARY KEY (`user_id`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8;

/*Data for the table `tb_user` */

insert  into `tb_user`(`user_id`,`user_name`,`password`,`user_picture`,`user_address`,`phoneNumber`,`identity`,`user_store_id`) values 
(7,'vankykoo','qaz123456','https://p.qqan.com/up/2021-4/16197489293438932.jpg','广东省深圳市','18888888888',3,0),
(8,'Mary','qaz123456','https://p.qqan.com/up/2018-4/2018040511085481462.jpg','广东省河源市连平县商业广场','18800927312',2,5),
(9,'Leo','qaz123456','https://p.qqan.com/up/2018-5/2018050911304322378.jpg','广东省河源市','18088890823',2,6),
(10,'Mike','qaz123456','https://ts1.cn.mm.bing.net/th/id/R-C.3ccdd12565c69106cead7785617b7d82?rik=F2rAnmUpqekoWg&riu=http%3a%2f%2fpic.22520.cn%2fup%2f200810%2f1597065730129684.jpg&ehk=dfaIHqsfBFNcXzzJq1jLqZsw7m%2bA2T3d37bDpr8GiNc%3d&risl=&pid=ImgRaw&r=0','美国洛杉矶','19888238290',1,0);

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
