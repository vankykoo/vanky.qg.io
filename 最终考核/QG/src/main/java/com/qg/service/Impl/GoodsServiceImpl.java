package com.qg.service.Impl;

import com.qg.DAO.GoodsDAO;
import com.qg.pojo.Goods;
import com.qg.service.GoodsService;

import java.util.List;

public class GoodsServiceImpl implements GoodsService {
    private GoodsDAO goodsDAO = new GoodsDAO();

    @Override
    public List<Goods> selectAllGoods() {
        return goodsDAO.selectAllGoods();
    }

    @Override
    public List<Goods> selectAllGoodsOfCart(Integer userId) {
        return goodsDAO.selectAllGoodsOfCart(userId);
    }

    @Override
    public List<Goods> selectGoodsByName(String goodsName) {
        return goodsDAO.selectGoodsByName(goodsName);
    }

    @Override
    public void addToCart(Integer goodsId, Integer userId) {
        goodsDAO.addToCart(goodsId,userId);
    }

    @Override
    public void deleteFromCartByIds(Integer[] goodsIds, Integer userId) {
        goodsDAO.deleteFromCartByIds(goodsIds,userId);
    }

    @Override
    public List<Goods> selectByStoreId(Integer storeId) {
        String sql = "select * from tb_goods where goods_store_id =? and goods_state = 1";
        return goodsDAO.selectManyGoods(sql,storeId);
    }

    @Override
    public Integer addNewGoods(Goods goods) {
        goodsDAO.addNewGoods(goods);
        Integer goodsId = goodsDAO.getGoodsId();
        return goodsId;
    }

    @Override
    public void delistByGoodsId(Integer goodsId) {
        goodsDAO.delistByGoodsId(goodsId);
    }

    @Override
    public void deleteFromCartByGoodsId(Integer goodsId) {
        String sql = "delete from tb_cart where goods_id =?";
        goodsDAO.update(sql,goodsId);
    }

    @Override
    public void updateGoodsInStore(Goods goods) {
        String sql = "update tb_goods set " +
                "goods_name = ?,goods_picture = ?,goods_price =?," +
                "goods_inventory = ? where goods_id = ?";
        goodsDAO.update(sql, goods.getGoodsName(),goods.getGoodsPicture(),
                goods.getGoodsPrice(), goods.getInventory(),
                goods.getGoodsId());
    }

    @Override
    public void launchNewGoods(Integer goodsId) {
        String sql = "update tb_goods set goods_state = 1 where goods_id =?";
        goodsDAO.update(sql,goodsId);
    }

    @Override
    public List<Goods> selectGoodsByStoreName(String storeName) {
        return goodsDAO.selectGoodsByStoreName(storeName);
    }

    @Override
    public void handleAfterBuy(Integer goodsId) {
        String sqlForGoods = "select * from tb_goods where goods_id =?";
        Goods goods = goodsDAO.selectOneGoods(sqlForGoods, goodsId);
        Integer monthlySales = goods.getMonthlySales() + 1;
        Integer inventory = goods.getInventory() - 1;

        String sql = "update tb_goods set goods_inventory = ?,goods_monthly_sales = ? where goods_id =?";
        goodsDAO.update(sql,inventory,monthlySales,goodsId);
    }

    @Override
    public Integer selectGoodsInventory(Integer goodsId) {
        String sql = "select * from tb_goods where goods_id =?";
        return goodsDAO.selectOneGoods(sql, goodsId).getInventory();
    }
}
