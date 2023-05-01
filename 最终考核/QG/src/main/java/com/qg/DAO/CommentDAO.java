package com.qg.DAO;

import com.qg.pojo.Comment;
import com.qg.util.JDBCUtils;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class CommentDAO extends BasicDAO<Comment> {
    private JDBCUtils jdbcUtils = new JDBCUtils();

    public void remarkByGoodsId(Comment comment){
        String sql = "insert into tb_comment (goods_id,grade,description,user_id) values (?,?,?,?)";
        update(sql,comment.getGoodsId(),comment.getGrade(),comment.getDescription(),comment.getUserId());
    }

    public List<Comment> selectCommentByGoodsId(Integer goodsId){
        Comment comment = null;
        String sql = "select * from tb_comment where goods_id =?";
        ResultSet resultSet = select(sql, Comment.class, goodsId);
        List<Comment> commentList = new ArrayList<>();
        try {
            while(resultSet.next()){
                String grade = resultSet.getString(2);
                String description = resultSet.getString(3);
                Integer commentId = resultSet.getInt(4);
                Integer userId = resultSet.getInt(5);
                comment = new Comment(commentId,goodsId,grade,description,userId);
                commentList.add(comment);
            }
            return commentList;
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }finally {
            jdbcUtils.close(null,null,null);
        }
    }

    public void deleteByCommentId(Integer commentId){
        String sql = "delete from tb_comment where comment_id =?";
        update(sql,commentId);
    }
}
