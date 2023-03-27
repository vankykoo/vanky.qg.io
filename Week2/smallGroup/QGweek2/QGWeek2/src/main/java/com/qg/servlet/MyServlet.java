package com.qg.servlet;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;

/**
 * @author vanky
 */

public class MyServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        System.out.println("=================================");
        //获取请求方式
        String method = request.getMethod();
        System.out.println("请求方式=" + method);

        String username = "";
        String password = "";
        String file = "";
        String text = "";

        if("GET".equals(method)){
            //获取请求参数
            username = request.getParameter("usernameOfGet");
            password = request.getParameter("passwordOfGet");
            file = request.getParameter("fileOfGet");
            text = request.getParameter("description");

            /*-------------tomcat8以下版本：需要URL编码+解码---------------------------
            username = new String(username.getBytes(StandardCharsets.ISO_8859_1),StandardCharsets.UTF_8);
            file = new String(file.getBytes(StandardCharsets.ISO_8859_1),StandardCharsets.UTF_8);
            text = new String(text.getBytes(StandardCharsets.ISO_8859_1),StandardCharsets.UTF_8);
            ----------------------------------------------------------------------*/

            System.out.println("文件上传成功：" + file);
            System.out.println("请求参数：" + "usernameOfGet=" + username + "&"+ "passwordOfGet=" + password);
            System.out.println("文本描述：" + text);
        }else {
            username = request.getParameter("usernameOfPost");
            password = request.getParameter("passwordOfPost");
            text = request.getParameter("description");
            file = request.getParameter("fileOfPost");
            System.out.println("文件上传成功：" + file);
            System.out.println("请求参数：" + "usernameOfPost=" + username + "&"+ "passwordOfPost=" + password);
            System.out.println("文本描述：" + text);
        }
        //在客户端打印响应数据
        response.setContentType("text/html;charset=utf-8");
        PrintWriter writer = response.getWriter();
        writer.write("你好 " + username);
        writer.write("<br><h1>HAVE A NICE DAY!<h1>");
        writer.flush();
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doGet(request, response);
    }
}
