package com.qg.web;

import com.alibaba.fastjson.JSON;
import com.qg.pojo.Goods;
import com.qg.pojo.Store;
import com.qg.service.GoodsService;
import com.qg.service.Impl.GoodsServiceImpl;
import com.qg.service.Impl.StoreServiceImpl;
import com.qg.service.StoreService;
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
@WebServlet("/store/*")
public class StoreServlet extends BaseServlet{
    StoreService storeService = new StoreServiceImpl();

    public void selectAllStores(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        //1.调用Service查询
        List<Store> storesList = storeService.selectAllStores();
        //2.转为JSON
        String jsonString = JSON.toJSONString(storesList);
        //3.写数据
        response.setContentType("text/json;charset=utf-8");
        response.getWriter().write(jsonString);
    }

    public void selectStoresByName(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        //1.读取数据
        BufferedReader br = request.getReader();
        String params = br.readLine();
        //2.读取的数据放到node中
        ObjectMapper mapper = new ObjectMapper();
        JsonNode node = mapper.readTree(params);
        //3.从node中读取数据
        String storeName = node.get("storeName").asText();

        //如果搜索框为空
        if(storeName == null){
            selectAllStores(request,response);
            return;
        }

        //给goodsName加上模糊查询标志
        storeName = "%" + storeName + "%";

        //4.调用Service查询
        List<Store> storesList = storeService.selectStoreByName(storeName);
        //5.转为JSON
        String jsonString = JSON.toJSONString(storesList);
        //6.写数据
        response.setContentType("text/json;charset=utf-8");
        response.getWriter().write(jsonString);
    }

    //查找自己的店铺
    public void selectStoresByUserId(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        //1.读取数据
        BufferedReader br = request.getReader();
        String params = br.readLine();
        //2.读取的数据放到node中
        ObjectMapper mapper = new ObjectMapper();
        JsonNode node = mapper.readTree(params);
        //3.从node中读取用户ID
        Integer userId = node.get("userId").asInt();
        List<Store> storeList = new ArrayList<>();

        //4.调用Service查询
        Store store = storeService.selectStoreByUserId(userId);
        storeList.add(store);
        //5.转为JSON
        String jsonString = JSON.toJSONString(storeList);
        //6.写数据
        response.setContentType("text/json;charset=utf-8");
        response.getWriter().write(jsonString);
    }

    //修改自己的店铺
    public void updateStore(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        //1.读取数据
        BufferedReader br = request.getReader();
        String params = br.readLine();
        //2.读取的数据放到node中
        ObjectMapper mapper = new ObjectMapper();
        JsonNode node = mapper.readTree(params);
        //3.从node中读取数据
        Integer storeId = node.get("storeId").asInt();
        String storeName = node.get("storeName").asText();
        String storeLogo = node.get("storeLogo").asText();
        String storeAddress = node.get("storeAddress").asText();

        Store store = new Store(storeId,storeName,storeLogo,storeAddress,null);

        //4.调用Service查询
        storeService.updateStore(store);
        //5.写数据
        response.setContentType("text/json;charset=utf-8");
        response.getWriter().write("success");
    }


}
