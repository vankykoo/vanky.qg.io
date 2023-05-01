package com.qg.service;

import com.qg.pojo.Goods;

import java.util.List;

public interface GoodsService {

    /**
     * 查找所有商品数据
     * @return List<Goods>
     */
    List<Goods> selectAllGoods();

    /**
     * 购物车商品
     * @return List<Goods>
     */
    List<Goods> selectAllGoodsOfCart(Integer userId);

    /**
     * 搜索商品
     * @param goodsName
     * @return  商品列表
     */
    List<Goods> selectGoodsByName(String goodsName);

    /**
     * 加入购物车
     * @param goodsId
     * @param userId
     */
    void addToCart(Integer goodsId,Integer userId);

    /**
     * 移出购物车（也用于购买后移出购物车）
     * @param goodsIds
     * @param userId
     */
    void deleteFromCartByIds(Integer[] goodsIds,Integer userId);

    /**
     * 查看自己店铺的商品
     * @param storeId
     * @return
     */
    List<Goods> selectByStoreId(Integer storeId);

    /**
     * 上传新商品
     * @param goods
     */
    Integer addNewGoods(Goods goods);

    /**
     * 下架商品
     * @param goodsId
     */
    void delistByGoodsId(Integer goodsId);

    /**
     * 商品下架后从购物车删除
     * @param goodsId
     */
    void deleteFromCartByGoodsId(Integer goodsId);

    /**
     * 上架修改商品信息
     * @param goods
     */
    void updateGoodsInStore(Goods goods);

    /**
     * 上架新商品
     * @param goodsId
     */
    void launchNewGoods(Integer goodsId);

    /**
     * 用店铺名查找商品
     * @param storeName
     * @return
     */
    List<Goods> selectGoodsByStoreName(String storeName);

    /**
     * 购买后库存和月销量改变
     * @param goodsId
     */
    void handleAfterBuy(Integer goodsId);

    /**
     * 查看库存
     * @param goodsId
     * @return
     */
    Integer selectGoodsInventory(Integer goodsId);
}
