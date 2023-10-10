# 1 git push 时报文件过大如何删除commit 历史中记录
[网页连接](https://blog.csdn.net/HappyRocking/article/details/89313501)

# 2 查看所有commit记录包括当前commit之后的
git reflog

# 3 git合并分支时当前分支落后于主分支的处理步骤
## 3.1 该情况会导致的问题
1 直接报冲突导致合并不成功

2 因为分支落后于主分支，所以主分支新增及修改当前分支不知道容易覆盖导致影响其它开发
## 3.2 解决方法
### 3.2.1 方法一使用git命令
1 相关连接 https://blog.csdn.net/daerzei/article/details/97615665

2 步骤总结

2.1 解决思路

解决思路：
- 假设当前开发的分支名为：feature/dev         []
- 根据主分支（origin）代码在本地创建新的临时分支，命名为temp
- 将临时分支（temp）合并到开发分支（eature/dev）
- 解决合并后的冲突
- 提交开发分支（feature/dev）并push到远程仓库
- 后将开发分支（feature/dev）合并到主分支（origin



### 3.2.2 借助vscode
1 连接  https://blog.csdn.net/weixin_45811256/article/details/121018000
