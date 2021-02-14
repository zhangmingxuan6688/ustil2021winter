创建表：
create table sql(
name(10),
sex(2),
age(20)
);
//增：
insert into sql values(‘名’,‘性’,‘年龄’);
insert into sql values（‘张三’,‘男’,‘21’);
insert into sql values（‘李四’,‘女’,‘20’);
//查
select * from sql
where age= 21 and name="张三";
//删：
delete from sql where age=20;//将李四删掉
//改：
update sql set '年龄'=22 where '姓名'='张三';
