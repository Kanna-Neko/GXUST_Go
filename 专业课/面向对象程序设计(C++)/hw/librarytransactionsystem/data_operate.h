//
// Created by 胡思佳 on 2020/6/21.
//

#ifndef LIBRARYTRANSACTIONSYSTEM_DATA_OPERATE_H
#define LIBRARYTRANSACTIONSYSTEM_DATA_OPERATE_H
#include<string>
#include"database.h"
#include<vector>
using namespace std;
namespace verify{
    //验证账号密码的正确
    bool verify_account(const string& input_id,const string& input_password);
    //返回正在售卖的书籍
    vector<book> get_selling_books();
}
namespace dataOperate{
    //修改公告
    void revise_announcement(const string& new_announcement);
    //存数据
    void store_data();
    //取信息
    void pull_data();
}
#endif //LIBRARYTRANSACTIONSYSTEM_DATA_OPERATE_H
