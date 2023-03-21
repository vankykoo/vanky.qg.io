package com.qg.poolUtils;

import java.sql.Connection;

public interface IPool {
        /**
         * 取新的数据库连接
         *
         * @return Connection
         * @throws InterruptedException
         */
        Connection getPoolConnection() throws InterruptedException;


}
