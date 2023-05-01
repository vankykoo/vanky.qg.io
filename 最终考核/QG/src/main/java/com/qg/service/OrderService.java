package com.qg.service;

import com.qg.pojo.Order;

import java.util.List;

public interface OrderService {
    /**
     * 查找自己所有的订单
     * @param userId
     * @return
     */
    List<Order> selectAllOrders(Integer userId);

    /**
     * 购买后加入到订单
     * @param goodsIds
     * @param userId
     */
    void addToOrderByIds(Integer[] goodsIds,Integer userId);

    /**
     * 查看自己商店的订单
     * @param storeId
     * @return
     */
    List<Order> selectByStoreId(Integer storeId);

    /**
     * 发货
     * @param orderId
     */
    void sendOutGoods(Integer orderId);

    /**
     * 处理售后
     * @param orderId
     */
    void afterService(Integer orderId);

    /**
     * 确认收货
     * @param orderId
     */
    void confirmReceipt(Integer orderId);

    /**
     * 客户申请售后
     * @param orderId
     */
    void applyServiceAfterSales(Integer orderId);

    /**
     * 订单完成
     * @param orderId
     */
    void orderCompleted(Integer orderId);
}
