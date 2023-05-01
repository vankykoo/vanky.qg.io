package com.qg.web;

import com.alibaba.fastjson.JSON;
import com.qg.pojo.Goods;
import com.qg.pojo.Notice;
import com.qg.service.GoodsService;
import com.qg.service.Impl.GoodsServiceImpl;
import com.qg.service.Impl.NoticeServiceImpl;
import com.qg.service.Impl.UserServiceImpl;
import com.qg.service.NoticeService;
import com.qg.service.UserService;
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
import java.util.ArrayList;
import java.util.List;

/**
 * @author vanky
 */
@WebServlet("/goods/*")
public class GoodsServlet extends BaseServlet{
    GoodsService goodsService = new GoodsServiceImpl();
    UserService userService = new UserServiceImpl();
    NoticeService noticeService = new NoticeServiceImpl();

    public void selectAllGoods(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        //1.调用Service查询
        List<Goods> goodsList = goodsService.selectAllGoods();
        //2.转为JSON
        String jsonString = JSON.toJSONString(goodsList);
        //3.写数据
        response.setContentType("text/json;charset=utf-8");
        response.getWriter().write(jsonString);
    }

    public void selectAllGoodsOfCart(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        //1.读取数据
        BufferedReader br = request.getReader();
        String params = br.readLine();
        //2.读取的数据放到node中
        ObjectMapper mapper = new ObjectMapper();
        JsonNode node = mapper.readTree(params);
        //3.从node中读取用户ID
        Integer userId = node.get("userId").asInt();
        //4.调用Service查询
        List<Goods> goodsList = goodsService.selectAllGoodsOfCart(userId);
        //5.转为JSON
        String jsonString = JSON.toJSONString(goodsList);
        //6.写数据
        response.setContentType("text/json;charset=utf-8");
        response.getWriter().write(jsonString);
    }

    //查询商品
    public void selectGoodsByName(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        //1.读取数据
        BufferedReader br = request.getReader();
        String params = br.readLine();
        //2.读取的数据放到node中
        ObjectMapper mapper = new ObjectMapper();
        JsonNode node = mapper.readTree(params);
        //3.从node中读取用户名
        String goodsName = node.get("goodsName").asText();

        //如果搜索框为空
        if(goodsName == null){
            selectAllGoods(request,response);
            return;
        }

        //给goodsName加上模糊查询标志
        goodsName = "%" + goodsName + "%";
        //1.调用Service查询
        List<Goods> goodsList = goodsService.selectGoodsByName(goodsName);
        //2.转为JSON
        String jsonString = JSON.toJSONString(goodsList);
        //3.写数据
        response.setContentType("text/json;charset=utf-8");
        response.getWriter().write(jsonString);
    }

    //加入购物车
    public void addToCart(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        //1.读取数据
        BufferedReader br = request.getReader();
        String params = br.readLine();
        //2.读取的数据放到node中
        ObjectMapper mapper = new ObjectMapper();
        JsonNode node = mapper.readTree(params);
        //3.从node中读取ID
        Integer goodsId = node.get("goodsId").asInt();
        Integer userId = node.get("userId").asInt();

        //4.调用Service修改
        goodsService.addToCart(goodsId,userId);
        //5.写数据
        response.setContentType("text/json;charset=utf-8");
        response.getWriter().write("success");
    }

    //移出购物车
    public void deleteFromCartByIds(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        //1.读取数据
        BufferedReader br = request.getReader();
        String params = br.readLine();
        //2.读取的数据放到node中
        ObjectMapper mapper = new ObjectMapper();
        JsonNode node = mapper.readTree(params);
        JsonNode goodsIdsNode = node.get("goodsIds");
        List<Integer> goodsIdsList = new ArrayList<>();

        if (goodsIdsNode != null && goodsIdsNode.isArray()) {
            // 3.处理 goodsIds 数组
            for (JsonNode idNode : goodsIdsNode) {
                int id = idNode.asInt();
                goodsIdsList.add(id);
            }
        }
        //转为数组
        Integer[] goodsIds = goodsIdsList.toArray(new Integer[0]);
        Integer userId = node.get("userId").asInt();

        //4.调用Service修改
        goodsService.deleteFromCartByIds(goodsIds,userId);
        //5.写数据
        response.setContentType("text/json;charset=utf-8");
        response.getWriter().write("success");
    }


    public void selectByStoreId(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        //1.读取数据
        BufferedReader br = request.getReader();
        String params = br.readLine();
        //2.读取的数据放到node中
        ObjectMapper mapper = new ObjectMapper();
        JsonNode node = mapper.readTree(params);
        //3.从node中读取用户ID
        Integer storeId = node.get("storeId").asInt();

        //4.调用Service查询
        List<Goods> goodsList = goodsService.selectByStoreId(storeId);
        //5.转为JSON
        String jsonString = JSON.toJSONString(goodsList);
        //6.写数据
        response.setContentType("text/json;charset=utf-8");
        response.getWriter().write(jsonString);
    }

    //下架商品
    public void deleteByGoodsId(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        //1.读取数据
        BufferedReader br = request.getReader();
        String params = br.readLine();
        //2.读取的数据放到node中
        ObjectMapper mapper = new ObjectMapper();
        JsonNode node = mapper.readTree(params);
        //3.从node中读取数据
        Integer goodsId = node.get("goodsId").asInt();
        Integer isWebManager = node.get("isWebManager").asInt();

        if (isWebManager == 1){
            Integer storeId = node.get("storeId").asInt();
            String goodsName = node.get("goodsName").asText();
            Integer userId = userService.selectUserByStoreId(storeId).getUserId();
            String noticeContent = "你的商品【" + goodsName + "】涉嫌违规，已被网站管理员下架";
            LocalDateTime now = LocalDateTime.now();
            DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
            String formattedDateTime = now.format(formatter);
            Notice notice = new Notice(formattedDateTime,noticeContent,userId);
            noticeService.addNotice(notice);
        }

        //4.调用Service查询
        goodsService.delistByGoodsId(goodsId);
        goodsService.deleteFromCartByGoodsId(goodsId);
        //5.写数据
        response.setContentType("text/json;charset=utf-8");
        response.getWriter().write("success");
    }

    //商家修改商品信息
    public void updateGoodsInStore(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        //1.读取数据
        BufferedReader br = request.getReader();
        String params = br.readLine();
        //2.读取的数据放到node中
        ObjectMapper mapper = new ObjectMapper();
        JsonNode node = mapper.readTree(params);
        //3.从node中读取数据
        Integer goodsId = node.get("goodsId").asInt();
        String goodsName = node.get("goodsName").asText();
        String goodsPicture = node.get("goodsPicture").asText();
        Integer goodsPrice = node.get("goodsPrice").asInt();
        Integer inventory = node.get("inventory").asInt();
        Goods goods = new Goods(goodsId,goodsName,null,goodsPicture,goodsPrice,inventory,null,null,null,null);

        //4.调用Service方法
        goodsService.updateGoodsInStore(goods);
        //5.写数据
        response.setContentType("text/json;charset=utf-8");
        response.getWriter().write("success");
    }

    //用店铺名查找商品
    public void selectGoodsByStoreName(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        //1.读取数据
        BufferedReader br = request.getReader();
        String params = br.readLine();
        //2.读取的数据放到node中
        ObjectMapper mapper = new ObjectMapper();
        JsonNode node = mapper.readTree(params);
        //3.从node中读取
        String storeName = node.get("storeName").asText();

        if(storeName == null){
            selectAllGoods(request,response);
            return;
        }

        //给goodsName加上模糊查询标志
        storeName = "%" + storeName + "%";
        //4.调用Service查询
        List<Goods> goodsList = goodsService.selectGoodsByStoreName(storeName);
        //5.转为JSON
        String jsonString = JSON.toJSONString(goodsList);
        //6.写数据
        response.setContentType("text/json;charset=utf-8");
        response.getWriter().write(jsonString);
    }

}
