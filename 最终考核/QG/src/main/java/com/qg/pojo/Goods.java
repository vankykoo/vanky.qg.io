package com.qg.pojo;

import com.qg.service.Impl.StoreServiceImpl;
import com.qg.service.StoreService;

import java.util.List;

public class Goods {
    //商品id
    private Integer goodsId;
    //商品名
    private String goodsName;
    //商品介绍
    private String goodsDescription;
    //图片
    private String goodsPicture;
    //价格
    private Integer goodsPrice;
    //库存
    private Integer inventory;
    /**
     * goodsState
     * 1上架，2未上架
     */
    private Integer goodsState;
    //评论List集合
    private List<Comment> comments;
    //月销量
    private Integer monthlySales;
    //所属店铺
    private Integer storeId;

    public Goods() {
    }

    public Goods(Integer goodsId, String goodsName, String goodsDescription, String goodsPicture, Integer goodsPrice, Integer inventory, Integer goodsState, List<Comment> comments, Integer monthlySales, Integer storeId) {
        this.goodsId = goodsId;
        this.goodsName = goodsName;
        this.goodsDescription = goodsDescription;
        this.goodsPicture = goodsPicture;
        this.goodsPrice = goodsPrice;
        this.inventory = inventory;
        this.goodsState = goodsState;
        this.comments = comments;
        this.monthlySales = monthlySales;
        this.storeId = storeId;
    }

    public Integer getGoodsId() {
        return goodsId;
    }

    public void setGoodsId(Integer goodsId) {
        this.goodsId = goodsId;
    }

    public String getGoodsName() {
        return goodsName;
    }

    public void setGoodsName(String goodsName) {
        this.goodsName = goodsName;
    }

    public String getGoodsDescription() {
        return goodsDescription;
    }

    public void setGoodsDescription(String goodsDescription) {
        this.goodsDescription = goodsDescription;
    }

    public String getGoodsPicture() {
        return goodsPicture;
    }

    public void setGoodsPicture(String goodsPicture) {
        this.goodsPicture = goodsPicture;
    }

    public Integer getGoodsPrice() {
        return goodsPrice;
    }

    public void setGoodsPrice(Integer goodsPrice) {
        this.goodsPrice = goodsPrice;
    }

    public Integer getInventory() {
        return inventory;
    }

    public void setInventory(Integer inventory) {
        this.inventory = inventory;
    }

    public Integer getGoodsState() {
        return goodsState;
    }

    public void setGoodsState(Integer goodsState) {
        this.goodsState = goodsState;
    }

    public List<Comment> getComments() {
        return comments;
    }

    public void setComments(List<Comment> comments) {
        this.comments = comments;
    }

    public Integer getMonthlySales() {
        return monthlySales;
    }

    public void setMonthlySales(Integer monthlySales) {
        this.monthlySales = monthlySales;
    }

    public Integer getStoreId() {
        return storeId;
    }

    public void setStoreId(Integer goodsStoreId) {
        this.storeId = goodsStoreId;
    }

    //逻辑视图
    public String getGoodsStateStr(){
        if (goodsState == null){
            return "未知";
        }
        return goodsState == 1 ? "已上架":"未上架";
    }

    public String getStoreName(){
        StoreService storeService = new StoreServiceImpl();
        Store store = storeService.selectStoreById(storeId);
        if (store != null){
            return store.getStoreName();
        }
        return null;
    }

    @Override
    public String toString() {
        return "Goods{" +
                "goodsId=" + goodsId +
                ", goodsName='" + goodsName + '\'' +
                ", goodsDescription='" + goodsDescription + '\'' +
                ", goodsPicture='" + goodsPicture + '\'' +
                ", goodsPrice=" + goodsPrice +
                ", inventory=" + inventory +
                ", goodsState=" + goodsState +
                ", comments=" + comments +
                ", monthlySales=" + monthlySales +
                ", storeId=" + storeId +
                '}';
    }

}
