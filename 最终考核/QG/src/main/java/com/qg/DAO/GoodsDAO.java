package com.qg.DAO;

import com.qg.pojo.Goods;
import com.qg.pojo.Store;
import com.qg.util.JDBCUtils;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class GoodsDAO extends BasicDAO<Goods> {
    private JDBCUtils jdbcUtils = new JDBCUtils();

    //封装查找
    public List<Goods> selectManyGoods(String sql, Object... params) {
        BasicDAO<Goods> basicDAO =new BasicDAO<>();
        Goods goods = null;
        List<Goods> goodsList = new ArrayList<>();
        ResultSet resultSet = basicDAO.select(sql, Goods.class, params);
        String sqlToGoods = "select * from tb_goods where goods_id =?";
        try {
            while (resultSet.next()) {
                Integer goodsId = resultSet.getInt(1);
                goods = selectOneGoods(sqlToGoods, goodsId);
                goodsList.add(goods);
            }
            return goodsList;
        } catch (SQLException e) {
            throw new RuntimeException(e);
        } finally {
            jdbcUtils.close(null, null, null);
        }
    }

    //封装查找单个
    public Goods selectOneGoods(String sql, Object... params) {
        BasicDAO<Goods> basicDAO =new BasicDAO<>();
        Goods goods = null;
        ResultSet resultSet = basicDAO.select(sql, Goods.class, params);
        try {
            if (resultSet.next()) {
                Integer goodsId = resultSet.getInt(1);
                //这里还需要获取一下评论内容
                String goodsName = resultSet.getNString(2);
                Integer inventory = resultSet.getInt(3);
                Integer goodsState = resultSet.getInt(4);
                Integer monthlySales = resultSet.getInt(5);
                String goodsPicture = resultSet.getNString(6);
                Integer goodsStoreId = resultSet.getInt(7);
                String description = resultSet.getNString(8);
                Integer goodsPrice = resultSet.getInt(9);
                goods = new Goods();
                goods.setGoodsId(goodsId);
                goods.setGoodsName(goodsName);
                goods.setInventory(inventory);
                goods.setGoodsState(goodsState);
                goods.setMonthlySales(monthlySales);
                goods.setGoodsPicture(goodsPicture);
                goods.setStoreId(goodsStoreId);
                goods.setGoodsDescription(description);
                goods.setGoodsPrice(goodsPrice);
            }
            return goods;
        } catch (SQLException e) {
            throw new RuntimeException(e);
        } finally {
            jdbcUtils.close(null, null, null);
        }
    }

    //查找所有商品数据
    public List<Goods> selectAllGoods() {
        String sql = "select * from tb_goods where goods_state = 1";
        return selectManyGoods(sql);
    }

    //查找所有商品数据
    public List<Goods> selectAllGoodsOfCart(Integer userId) {
        //sql语句
        String sql = "select goods_id from tb_cart where user_id =?";
        //得到goodsId
        ResultSet resultSetOfGoodsId = select(sql, Goods.class, userId);
        //通过goodsId查找goods，返回goodsList
        List<Goods> goodsList = new ArrayList<>();
        String sqlToGoods = "select * from tb_goods where goods_id =?";
        try {
            while (resultSetOfGoodsId.next()) {
                Goods goods = selectOneGoods(sqlToGoods, resultSetOfGoodsId.getInt(1));
                goodsList.add(goods);
            }
            return goodsList;
        } catch (SQLException e) {
            throw new RuntimeException(e);
        } finally {
            jdbcUtils.close(null, null, null);
        }
    }

    //条件查询
    public List<Goods> selectGoodsByName(String goodsName) {
        String sql = "select * from tb_goods where goods_name like ? and goods_state =1";
        return selectManyGoods(sql, goodsName);
    }

    //加入购物车：Insert
    public void addToCart(Integer goodsId, Integer userId) {
        String sql = "insert into tb_cart (goods_id,user_id) values (?,?)";
        update(sql, goodsId, userId);
    }

    //移出购物车:delete
    public void deleteFromCartByIds(Integer[] goodsIds, Integer userId) {
        String sql = "delete from tb_cart where user_id =? and goods_id =?";
        for (Integer goodsId : goodsIds) {
            update(sql, userId, goodsId);
        }
    }

    //添加新商品
    public void addNewGoods(Goods goods) {
        String sql = "insert into tb_goods " +
                "(goods_name,goods_inventory,goods_state,goods_monthly_sales," +
                "goods_picture,goods_store_id,goods_description,goods_price)" +
                "values (?,?,?,?,?,?,?,?)";
        update(sql, goods.getGoodsName(), goods.getInventory(), goods.getGoodsState(), goods.getMonthlySales(),
                goods.getGoodsPicture(), goods.getStoreId(), goods.getGoodsDescription(), goods.getGoodsPrice());
    }

    //商家下架商品（删除）
    public void delistByGoodsId(Integer goodsId) {
        String sql = "update tb_goods set goods_state = 2 where goods_id =?";
        update(sql, goodsId);
    }

    //获取最后插入的记录的goodsId
    public Integer getGoodsId(){
        String sql = "select * from tb_goods order by goods_id desc limit 1";
        Goods goods = selectOneGoods(sql);
        return goods.getGoodsId();
    }

    public List<Goods> selectGoodsByStoreName(String storeName){
        String sql = "select * from tb_goods where goods_store_id =? and goods_state = 1";
        StoreDAO storeDAO = new StoreDAO();
        List<Store> storeList = storeDAO.selectStoreByName(storeName);
        if (!storeList.isEmpty()){
            Store store = storeList.get(0);
            Integer storeId = store.getStoreId();
            List<Goods> goodsList = selectManyGoods(sql, storeId);
            return goodsList;
        }
        return null;
    }

}

