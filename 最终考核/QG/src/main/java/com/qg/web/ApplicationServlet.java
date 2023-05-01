package com.qg.web;

import com.alibaba.fastjson.JSON;
import com.qg.pojo.*;
import com.qg.service.*;
import com.qg.service.Impl.*;
import org.codehaus.jackson.JsonNode;
import org.codehaus.jackson.map.ObjectMapper;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.BufferedReader;
import java.io.IOException;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.List;

/**
 * @author vanky
 */

@WebServlet("/application/*")
public class ApplicationServlet extends BaseServlet{
    ApplicationService applicationService = new ApplicationServiceImpl();
    StoreService storeService = new StoreServiceImpl();
    UserService userService = new UserServiceImpl();
    GoodsService goodsService = new GoodsServiceImpl();
    NoticeService noticeService = new NoticeServiceImpl();

    public void selectAllApplicationByUserId(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        //1.读取数据
        BufferedReader br = request.getReader();
        String params = br.readLine();
        //读取的数据放到node中
        ObjectMapper mapper = new ObjectMapper();
        JsonNode node = mapper.readTree(params);
        //从node中读取用户ID
        Integer userId = node.get("userId").asInt();

        //1.调用Service查询
        List<Application> applicationList = applicationService.selectAllApplicationByUserId(userId);
        //2.转为JSON
        String jsonString = JSON.toJSONString(applicationList);
        //3.写数据
        response.setContentType("text/json;charset=utf-8");
        response.getWriter().write(jsonString);
    }

    //提交开店申请
    public void openStoreApplication(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException{
        request.setCharacterEncoding("utf-8");
        //1.读取数据
        BufferedReader br = request.getReader();
        String params = br.readLine();
        //读取的数据放到node中
        ObjectMapper mapper = new ObjectMapper();
        JsonNode node = mapper.readTree(params);
        //从node中读取用户ID
        String applicationName = node.get("name").asText();
        Integer userId = node.get("userId").asInt();
        String applicationPic = node.get("applicationPic").asText();
        String description = node.get("description").asText();
        String userName = node.get("userName").asText();
        String address = node.get("address").asText();

        Application application = new Application();
        application.setName(applicationName);
        application.setApplicationUserId(userId);
        application.setApplicationPic(applicationPic);
        application.setDescription(description);
        application.setApplicationUserName(userName);
        application.setAddress(address);
        application.setApplicationState(0);
        application.setApplicationType(1);

        //2.调用Service修改
        applicationService.addToApplication(application);
        //3.写数据
        response.setContentType("text/json;charset=utf-8");
        response.getWriter().write("success");
    }

    //添加新商品
    public void addNewGoods(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        //1.读取数据
        BufferedReader br = request.getReader();
        String params = br.readLine();
        //读取的数据放到node中
        ObjectMapper mapper = new ObjectMapper();
        JsonNode node = mapper.readTree(params);
        //从node中读取数据
        Integer storeId = node.get("storeId").asInt();
        String goodsName = node.get("goodsName").asText();
        String goodsPicture = node.get("goodsPicture").asText();
        String goodsDescription = node.get("goodsDescription").asText();
        Integer userId = node.get("userId").asInt();
        //调用Service查询
        Store store = storeService.selectStoreByUserId(userId);
        User user = userService.selectById(userId);

        Goods goods = new Goods(null,goodsName,goodsDescription,
                goodsPicture,99999,0,2,null,
                0,storeId);


        //2.调用Service方法
        Integer goodsId = goodsService.addNewGoods(goods);

        Application application = new Application(null,2,
                userId,user.getUserName(),goodsName,
                goodsPicture,goodsDescription,null,
                null,store.getStoreAddress(),goodsId);

        applicationService.addToApplication(application);
        //3.写数据
        response.setContentType("text/json;charset=utf-8");
        response.getWriter().write("success");
    }

    //查看所有的申请
    public void selectAllApplication(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        //1.调用Service查询
        List<Application> applicationList = applicationService.selectAllApplication();
        //2.转为JSON
        String jsonString = JSON.toJSONString(applicationList);
        //3.写数据
        response.setContentType("text/json;charset=utf-8");
        response.getWriter().write(jsonString);
    }

    //处理申请
    public void handleApplication(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        //1.读取数据
        BufferedReader br = request.getReader();
        String params = br.readLine();
        //读取的数据放到node中
        ObjectMapper mapper = new ObjectMapper();
        JsonNode node = mapper.readTree(params);
        //从node中读取
        Integer applicationId = node.get("applicationId").asInt();
        Integer applicationType = node.get("applicationType").asInt();
        Integer applicationUserId = node.get("applicationUserId").asInt();
        String name = node.get("name").asText();
        String applicationPic = node.get("applicationPic").asText();
        String address = node.get("address").asText();
        Integer goodsId = node.get("goodsId").asInt();
        Integer isAgree = node.get("isAgree").asInt();

        //获取当前时间
        String noticeContent = "";
        LocalDateTime now = LocalDateTime.now();
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
        String formattedDateTime = now.format(formatter);

        //2.调用Service方法
        //同意
        if (isAgree == 1){
            if(applicationType == 1){
                //申请开店
                Store store = new Store(null,name,applicationPic,address,applicationUserId);
                storeService.openStore(store);
                userService.openStore(applicationUserId);
                noticeContent = "恭喜你，开店申请已审核通过！";
            }else {
                //申请上架商品
                goodsService.launchNewGoods(goodsId);
                noticeContent = "恭喜你，上架商品申请已审核通过！";
            }
        }else {
            //不同意
            if (applicationType == 1){
                noticeContent = "很抱歉，你的开店申请涉嫌违规，请修改后重新上传！";
            }else {
                noticeContent = "很抱歉，你的上架商品申请涉嫌违规，请修改后重新上传！";
            }

        }
        //发通知
        Notice notice = new Notice(formattedDateTime,noticeContent,applicationUserId);
        noticeService.addNotice(notice);
        applicationService.handleApplication(applicationId,isAgree);
        //3.写数据
        response.setContentType("text/json;charset=utf-8");
        response.getWriter().write("success");
    }

    //查看所有通知
    public void selectAllNotice(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        //1.读取数据
        BufferedReader br = request.getReader();
        String params = br.readLine();
        //读取的数据放到node中
        ObjectMapper mapper = new ObjectMapper();
        JsonNode node = mapper.readTree(params);
        //从node中读取
        Integer userId = node.get("userId").asInt();

        //1.调用Service查询
        List<Notice> noticeList = noticeService.selectAllNotice(userId);
        //2.转为JSON
        String jsonString = JSON.toJSONString(noticeList);
        //3.写数据
        response.setContentType("text/json;charset=utf-8");
        response.getWriter().write(jsonString);
    }


}
