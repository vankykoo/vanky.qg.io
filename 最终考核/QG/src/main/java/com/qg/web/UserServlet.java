package com.qg.web;

import com.alibaba.fastjson.JSON;
import com.qg.pojo.User;
import com.qg.service.Impl.UserServiceImpl;
import com.qg.service.UserService;
import com.qg.util.CheckCodeUtil;
import org.codehaus.jackson.JsonNode;
import org.codehaus.jackson.map.ObjectMapper;

import javax.servlet.ServletException;
import javax.servlet.ServletOutputStream;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * this is a servlet for test base servlet service method dispatch correct method invoking
 */
@WebServlet("/user/*")
public class UserServlet extends BaseServlet{
    UserService userService = new UserServiceImpl();

    private String codeAllSite;
    //查找用户是否存在
    public void selectUserByName(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        //1.读取数据
        BufferedReader br = request.getReader();
        String params = br.readLine();
        //2.读取的数据放到node中
        ObjectMapper mapper = new ObjectMapper();
        JsonNode node = mapper.readTree(params);
        //3.从node中读取输入的验证码
        String checkCode = node.get("checkCode").asText();

        //验证码错误
        if (!codeAllSite.equalsIgnoreCase(checkCode)){
            response.getWriter().write("checkCodeError");

            return;
        }
        //验证码正确
        String userString = node.get("user").toString();
        User user = JSON.parseObject(userString, User.class);

        //4.调用Service查询
        User userOfSql = userService.select(user.getUserName());
        if (userOfSql == null){
            //4.响应成功标识
            response.getWriter().write("success");
        }else{
            response.getWriter().write("error");
        }
    }

    //注册
    public void register(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException{
        //1.读取数据
        BufferedReader br = request.getReader();
        String params = br.readLine();

        //2.转为user对象
        User user = JSON.parseObject(params, User.class);
        //3.调用service方法添加数据
        userService.register(user);
        //4.响应成功标识
        response.getWriter().write("success");
    }

    //登录
    public void login(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        //1.读取数据
        BufferedReader br = request.getReader();
        String params = br.readLine();
        //读取的数据放到node中
        ObjectMapper mapper = new ObjectMapper();
        JsonNode node = mapper.readTree(params);
        //从node中读取输入的验证码
        String checkCode = node.get("checkCode").asText();
        //验证码错误
        if (!codeAllSite.equalsIgnoreCase(checkCode)){
            response.getWriter().write("checkCodeError");

            return;
        }
        //验证码正确
        String userString = node.get("userData").toString();
        //前端传入的user对象
        User user = JSON.parseObject(userString, User.class);
        String userName = user.getUserName();
        String password = user.getPassword();

        //3.调用Service查询
        //数据库中的user对象
        User userOfDb = userService.select(userName);
        String passwordOfDb = userOfDb.getPassword();

        if (passwordOfDb.equals(password)){
            //通过Map转为json发送到前端
            Map<String,Object> data = new HashMap<>();
            data.put("msg","success");
            data.put("user",userOfDb);
            String jsonString = JSON.toJSONString(data);
            //存数据到session
            HttpSession session = request.getSession();
            session.setAttribute("userId",userOfDb.getUserId());
            //4.响应成功标识
            response.getWriter().write(jsonString);
        }else{
            response.getWriter().write("passwordError");
        }
    }

    //验证码生成
    public void checkCode(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException{
        ServletOutputStream os = response.getOutputStream();
        String checkCodeGen = CheckCodeUtil.outputVerifyImage(100, 50, os, 4);

        //保存到全局变量中
        codeAllSite = checkCodeGen;
    }

    //跳转页面,同步信息
    public void synchronize(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException{
        HttpSession session = request.getSession();

        Integer userId = (Integer) session.getAttribute("userId");
        User user = userService.selectById(userId);

        String jsonString = JSON.toJSONString(user);
        response.setContentType("text/json;charset=utf-8");
        response.getWriter().write(jsonString);
    }

    //修改个人资料
    public void editData(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException{
        request.setCharacterEncoding("utf-8");
        //1.读取数据
        BufferedReader br = request.getReader();
        String params = br.readLine();
        //读取的数据放到node中
        ObjectMapper mapper = new ObjectMapper();
        JsonNode node = mapper.readTree(params);
        //读取数据
        Integer userId = node.get("userId").asInt();
        String userName = node.get("userName").asText();
        String userAddress = node.get("userAddress").asText();
        String userPicture = node.get("userPicture").asText();
        String phoneNumber = node.get("phoneNumber").asText();
        User user = new User(userId,userName,null,userPicture,userAddress,phoneNumber,null,null);

        //1.调用Service修改
        userService.editUserData(user);
        //3.写数据
        response.setContentType("text/json;charset=utf-8");
        response.getWriter().write("success");
    }

    //退出登录
    public void logout(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException{
        HttpSession session = request.getSession();
        session.setAttribute("userId",0);

        String jsonString = JSON.toJSONString(0);
        response.setContentType("text/json;charset=utf-8");
        response.getWriter().write(jsonString);
    }
}
