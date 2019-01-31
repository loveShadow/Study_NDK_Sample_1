package com.study.ndk;

/**
 * Created by Administrator on 2019/1/30.
 */

public class NDKDemo {
    /**
     * 求和算法
     * @param arg1 参数1
     * @param arg2 参数2
     * @return 和
     */
    public static native int sum(int arg1, int arg2);

    /**
     * 求积乘法
     * @param arg1 参数1
     * 另外一个乘数从Android侧获取
     * @return 积
     */
    public static native int mult(int arg1);
}
