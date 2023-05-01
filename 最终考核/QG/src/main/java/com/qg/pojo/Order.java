package com.qg.pojo;

import java.util.Date;

/**
 * 订单信息
 * @author vanky
 */
public class Order {
    //订单号
    private Integer orderId;
    //订单状态:是否发货，退换货，已收货
    private Integer orderState;
    //收货地址
    private String customerPlace;
    //订单商品名
    private String goodsName;
    //发货地址
    private String storeAddress;
    //客户id
    private Integer userId;
    //下单时间
    private String orderTime;
    //商品id
    private Integer goodsId;
    //商品图片
    private String goodsPicture;
    //商店Id
    private Integer storeId;
    //买家名字
    private String userName;
    //卖家电话
    private String phoneNumber;

    public Order() {
    }

    public Order(Integer orderId, Integer orderState, String customerPlace, String goodsName, String storeAddress, Integer userId, String orderTime, Integer goodsId, String goodsPicture, Integer storeId, String userName, String phoneNumber) {
        this.orderId = orderId;
        this.orderState = orderState;
        this.customerPlace = customerPlace;
        this.goodsName = goodsName;
        this.storeAddress = storeAddress;
        this.userId = userId;
        this.orderTime = orderTime;
        this.goodsId = goodsId;
        this.goodsPicture = goodsPicture;
        this.storeId = storeId;
        this.userName = userName;
        this.phoneNumber = phoneNumber;
    }

    public String getGoodsName() {
        return goodsName;
    }

    public void setGoodsName(String goodsName) {
        this.goodsName = goodsName;
    }

    public String getGoodsPicture() {
        return goodsPicture;
    }

    public void setGoodsPicture(String goodsPicture) {
        this.goodsPicture = goodsPicture;
    }

    public Integer getOrderId() {
        return orderId;
    }

    public void setOrderId(Integer orderId) {
        this.orderId = orderId;
    }

    public Integer getOrderState() {
        return orderState;
    }

    public void setOrderState(Integer orderState) {
        this.orderState = orderState;
    }

    public String getCustomerPlace() {
        return customerPlace;
    }

    public void setCustomerPlace(String customerPlace) {
        this.customerPlace = customerPlace;
    }

    public String getStoreAddress() {
        return storeAddress;
    }

    public void setStoreAddress(String storeAddress) {
        this.storeAddress = storeAddress;
    }

    public Integer getUserId() {
        return userId;
    }

    public void setUserId(Integer userId) {
        this.userId = userId;
    }

    public String getOrderTime() {
        return orderTime;
    }

    public void setOrderTime(String orderTime) {
        this.orderTime = orderTime;
    }

    public Integer getGoodsId() {
        return goodsId;
    }

    public void setGoodsId(Integer goodsId) {
        this.goodsId = goodsId;
    }

    public Integer getStoreId() {
        return storeId;
    }

    public void setStoreId(Integer storeId) {
        this.storeId = storeId;
    }

    public String getUserName() {
        return userName;
    }

    public void setUserName(String userName) {
        this.userName = userName;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    //逻辑视图
    public String getOrderStateStr(){
        switch (orderState){
            case 1:
                return "待发货";
            case 2:
                return "待收货";
            case 3:
                return "退还/售后";
            case 4:
                return "待评价";
            case 5:
                return "已完成";
            default:
                return "未知";
        }
    }


    @Override
    public String toString() {
        return "Order{" +
                "orderId=" + orderId +
                ", orderState=" + orderState +
                ", customerPlace='" + customerPlace + '\'' +
                ", goodsName='" + goodsName + '\'' +
                ", storeAddress='" + storeAddress + '\'' +
                ", userId=" + userId +
                ", orderTime='" + orderTime + '\'' +
                ", goodsId=" + goodsId +
                ", goodsPicture='" + goodsPicture + '\'' +
                ", storeId=" + storeId +
                ", userName='" + userName + '\'' +
                ", phoneNumber='" + phoneNumber + '\'' +
                '}';
    }

}
