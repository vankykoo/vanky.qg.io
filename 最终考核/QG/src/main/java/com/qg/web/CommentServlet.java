package com.qg.web;

import com.alibaba.fastjson.JSON;
import com.qg.pojo.Comment;
import com.qg.pojo.Notice;
import com.qg.service.CommentService;
import com.qg.service.Impl.CommentServiceImpl;
import com.qg.service.Impl.NoticeServiceImpl;
import com.qg.service.Impl.OrderServiceImpl;
import com.qg.service.NoticeService;
import com.qg.service.OrderService;
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
@WebServlet("/comment/*")
public class CommentServlet extends BaseServlet {
    private CommentService commentService = new CommentServiceImpl();
    private NoticeService noticeService = new NoticeServiceImpl();

    //查看评论
    public void selectCommentByGoodsId(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        //1.读取数据
        BufferedReader br = request.getReader();
        String params = br.readLine();
        //读取的数据放到node中
        ObjectMapper mapper = new ObjectMapper();
        JsonNode node = mapper.readTree(params);
        //从node中读取数据
        Integer goodsId = node.get("goodsId").asInt();

        //1.调用Service查询
        List<Comment> commentList = commentService.selectCommentByGoodsId(goodsId);
        String jsonString = JSON.toJSONString(commentList);
        //3.写数据
        response.setContentType("text/json;charset=utf-8");
        response.getWriter().write(jsonString);
    }

    public void remarkByGoodsId(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException{
        request.setCharacterEncoding("utf-8");
        //1.读取数据
        BufferedReader br = request.getReader();
        String params = br.readLine();
        //读取的数据放到node中
        ObjectMapper mapper = new ObjectMapper();
        JsonNode node = mapper.readTree(params);
        Integer orderId = node.get("orderId").asInt();
        String grade = node.get("grade").asText();
        String description = node.get("description").asText();
        Integer goodsId = node.get("goodsId").asInt();
        Integer userId = node.get("userId").asInt();
        Comment comment = new Comment(null,goodsId,grade,description,userId);

        //2.调用Service修改
        commentService.remarkByGoodsId(comment);
        OrderService orderService = new OrderServiceImpl();
        orderService.orderCompleted(orderId);

        //3.写数据
        response.setContentType("text/json;charset=utf-8");
        response.getWriter().write("success");
    }

    public void deleteByCommentId(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException{
        request.setCharacterEncoding("utf-8");
        //1.读取数据
        BufferedReader br = request.getReader();
        String params = br.readLine();
        System.out.println("deleteByCommentId params=" + params);
        //读取的数据放到node中
        ObjectMapper mapper = new ObjectMapper();
        JsonNode node = mapper.readTree(params);

        Integer userId = node.get("userId").asInt();
        Integer commentId = node.get("commentId").asInt();
        String commentContent = node.get("content").asText();

        String noticeContent = "你的评论：【" + commentContent + "】涉嫌违规，被网站管理员删除";
        LocalDateTime now = LocalDateTime.now();
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
        String formattedDateTime = now.format(formatter);
        Notice notice = new Notice(formattedDateTime,noticeContent,userId);

        //2.调用Service修改
        noticeService.addNotice(notice);
        commentService.deleteByCommentId(commentId);

        //3.写数据
        response.setContentType("text/json;charset=utf-8");
        response.getWriter().write("success");
    }
}
