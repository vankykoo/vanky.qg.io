package com.qg.web;

import com.alibaba.fastjson.JSON;
import com.alibaba.fastjson.JSONObject;
import com.fasterxml.jackson.databind.JsonNode;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.qg.pojo.User;
import com.qg.service.UserService;
import com.qg.service.UserServiceImpl;
import com.qg.util.CheckCodeUtil;

import javax.servlet.ServletException;
import javax.servlet.ServletOutputStream;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.BufferedReader;
import java.io.IOException;

@WebServlet("/user/*")
public class UserServlet extends BasicServlet{
    private UserService userService = new UserServiceImpl();
    private String codeAllSite;

    public void select(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        //1.读取数据
        BufferedReader br = request.getReader();
        String params = br.readLine();

        ObjectMapper mapper = new ObjectMapper();
        JsonNode node = mapper.readTree(params);

        String checkCode = node.get("checkCode").asText();

        if (!codeAllSite.equalsIgnoreCase(checkCode)){
            System.out.println("验证码错误");
            response.getWriter().write("checkCodeError");

            return;
        }
        String userString = node.get("user").toString();
        System.out.println("userString= " + userString);
        //2.转为user对象
        User user = JSON.parseObject(userString, User.class);

        System.out.println("userName=" + user.getUserName());

        //3.调用Service查询
        User userOfSql = userService.select(user.getUserName());
        System.out.println("userObject=" + userOfSql);

        if (userOfSql == null){
            //4.响应成功标识
            response.getWriter().write("success");
        }
    }

    public void add(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException{
        //1.读取数据
        BufferedReader br = request.getReader();
        String params = br.readLine();

        System.out.println("addUserParam =" + params);
        //2.转为user对象
        User user = JSON.parseObject(params, User.class);
        //3.调用service方法添加数据
        userService.add(user);
        //4.响应成功标识
        response.getWriter().write("success");
    }

    public void checkCode(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException{
        ServletOutputStream os = response.getOutputStream();
        String checkCodeGen = CheckCodeUtil.outputVerifyImage(100, 50, os, 4);

        //保存到全局变量中
        codeAllSite = checkCodeGen;

    }
}
