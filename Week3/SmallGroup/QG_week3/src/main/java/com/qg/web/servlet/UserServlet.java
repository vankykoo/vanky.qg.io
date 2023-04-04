package com.qg.web.servlet;

import com.qg.pojo.User;
import com.qg.service.UserService;
import com.qg.service.implement.UserServiceImp;
import org.codehaus.jackson.map.ObjectMapper;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

@WebServlet("/user/*")
public class UserServlet extends BasicServlet {
    private UserService userService = new UserServiceImp();


    public void login(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        //1.获取数据
        String userName = request.getParameter("userName");
        String password = request.getParameter("password");
        //后台展示输入数据
        System.out.println("输入的数据：userName=" + userName + "  password=" + password);

        //2.调用service方法登录
        User user = userService.login(userName, password);
        System.out.println(user);

        //3.封装
        Map<String, Object> map = new HashMap<>();
        map.put("status", 200);
        map.put("data", user);
        map.put("msg", (user != null) ? "用户存在，登录成功！" : "登录失败，用户不存在或密码错误！");
        //后台查看响应的数据
        System.out.println("响应的数据：" + map);
        //4.响应成功标识
        response.setContentType("text/html;charset=utf-8");
        ObjectMapper mapper = new ObjectMapper();
        mapper.writeValue(response.getWriter(), map);
    }

}
