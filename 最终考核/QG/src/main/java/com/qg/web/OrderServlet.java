package com.qg.web;

import com.alibaba.fastjson.JSON;
import com.qg.pojo.Order;
import com.qg.service.GoodsService;
import com.qg.service.Impl.GoodsServiceImpl;
import com.qg.service.Impl.OrderServiceImpl;
import com.qg.service.OrderService;
import org.codehaus.jackson.JsonNode;
import org.codehaus.jackson.map.ObjectMapper;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/**
 * @author vanky
 */
@WebServlet("/order/*")
public class OrderServlet extends BaseServlet {
    private OrderService orderService = new OrderServiceImpl();
    private GoodsService goodsService = new GoodsServiceImpl();

    //查看我的订单
    public void selectAllOrders(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        //1.读取数据
        BufferedReader br = request.getReader();
        String params = br.readLine();
        //2.读取的数据放到node中
        ObjectMapper mapper = new ObjectMapper();
        JsonNode node = mapper.readTree(params);
        //3.读取node中数据
        Integer userId = node.get("userId").asInt();

        //4.调用Service查询
        List<Order> orderList = orderService.selectAllOrders(userId);
        //5.转为JSON
        String jsonString = JSON.toJSONString(orderList);
        //6.写数据
        response.setContentType("text/json;charset=utf-8");
        response.getWriter().write(jsonString);
    }

    //加入到订单
    public void addToOrderByIds(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException{
        request.setCharacterEncoding("utf-8");
        //1.读取数据
        BufferedReader br = request.getReader();
        String params = br.readLine();
        //2.读取的数据放到node中
        ObjectMapper mapper = new ObjectMapper();
        JsonNode node = mapper.readTree(params);
        //3.读取node中的数据
        JsonNode ordersIdsNode = node.get("ordersIds");
        List<Integer> ordersIdsList = new ArrayList<>();

        if (ordersIdsNode != null && ordersIdsNode.isArray()) {
            // 处理 goodsIds 数组
            Integer inventory;
            for (JsonNode idNode : ordersIdsNode) {
                Integer id = idNode.asInt();
                inventory = goodsService.selectGoodsInventory(id);
                if (inventory <= 0){
                    response.setContentType("text/json;charset=utf-8");
                    response.getWriter().write("SellOut");
                    return;
                }
                ordersIdsList.add(id);
            }
        }
        GoodsService goodsService = new GoodsServiceImpl();
        //4.修改库存和月销量
        Integer[] ordersIds = ordersIdsList.toArray(new Integer[0]);
        for (int i = 0; i < ordersIds.length; i++) {
            goodsService.handleAfterBuy(ordersIds[i]);
        }
        Integer userId = node.get("userId").asInt();

        //5.调用Service修改
        orderService.addToOrderByIds(ordersIds,userId);
        //6.写数据
        response.setContentType("text/json;charset=utf-8");
        response.getWriter().write("success");
    }

    //查看自己店铺的订单
    public void selectByStoreId(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        //1.读取数据
        BufferedReader br = request.getReader();
        String params = br.readLine();
        //2.读取的数据放到node中
        ObjectMapper mapper = new ObjectMapper();
        JsonNode node = mapper.readTree(params);
        //获取node中的数据
        Integer storeId = node.get("storeId").asInt();

        //3.调用Service查询
        List<Order> orderList = orderService.selectByStoreId(storeId);
        //4.转为JSON
        String jsonString = JSON.toJSONString(orderList);
        //5.写数据
        response.setContentType("text/json;charset=utf-8");
        response.getWriter().write(jsonString);
    }

    //商家发货处理
    public void sendOutGoods(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        //1.读取数据
        BufferedReader br = request.getReader();
        String params = br.readLine();
        //2.读取的数据放到node中
        ObjectMapper mapper = new ObjectMapper();
        JsonNode node = mapper.readTree(params);
        //获取node中的数据
        Integer orderId = node.get("orderId").asInt();

        //4.调用Service查询
        orderService.sendOutGoods(orderId);
        //5.写数据
        response.setContentType("text/json;charset=utf-8");
        response.getWriter().write("success");
    }

    //商家处理售后
    public void afterService(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        //1.读取数据
        BufferedReader br = request.getReader();
        String params = br.readLine();
        //读取的数据放到node中
        ObjectMapper mapper = new ObjectMapper();
        JsonNode node = mapper.readTree(params);
        //获取node中的数据
        Integer orderId = node.get("orderId").asInt();

        //1.调用Service查询
        orderService.afterService(orderId);
        //3.写数据
        response.setContentType("text/json;charset=utf-8");
        response.getWriter().write("success");
    }

    //确认收货
    public void confirmReceipt(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        //1.读取数据
        BufferedReader br = request.getReader();
        String params = br.readLine();
        //读取的数据放到node中
        ObjectMapper mapper = new ObjectMapper();
        JsonNode node = mapper.readTree(params);
        Integer orderId = node.get("orderId").asInt();

        //1.调用Service查询
        orderService.confirmReceipt(orderId);
        //3.写数据
        response.setContentType("text/json;charset=utf-8");
        response.getWriter().write("success");
    }

    //客户申请售后
    public void applyServiceAfterSales(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        //1.读取数据
        BufferedReader br = request.getReader();
        String params = br.readLine();
        //读取的数据放到node中
        ObjectMapper mapper = new ObjectMapper();
        JsonNode node = mapper.readTree(params);
        Integer orderId = node.get("orderId").asInt();

        //1.调用Service查询
        orderService.applyServiceAfterSales(orderId);
        //3.写数据
        response.setContentType("text/json;charset=utf-8");
        response.getWriter().write("success");
    }
}
