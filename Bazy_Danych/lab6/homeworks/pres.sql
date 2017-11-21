use Northwind
--1
select CategoryName,sum(UnitsOnOrder) from Orders join [Order Details] on [Order Details].OrderID=Orders.OrderID 
join Products on [Order Details].ProductID=Products.ProductID join Categories on Categories.CategoryID=Products.CategoryID group by Categories.CategoryName
--2
select sum(Quantity) as 'Quantity',Customers.ContactName from Orders join [Order Details] on [Order Details].OrderID=Orders.OrderID join Customers on Customers.CustomerID=Orders.CustomerID group by Orders.OrderID, Customers.ContactName
--3
select sum(Quantity) as Quantity,Customers.ContactName from Orders join [Order Details] on [Order Details].OrderID=Orders.OrderID join Customers on Customers.CustomerID=Orders.CustomerID group by Orders.OrderID, Customers.ContactName having sum(Quantity)>250
--4
select distinct Customers.CustomerID,Customers.ContactName,ProductName from Orders join Customers on Orders.CustomerID=Customers.CustomerID join [Order Details] on Orders.OrderID=[Order Details].OrderID join Products on Products.ProductID=[Order Details].ProductID
--5
select Customers.ContactName, sum([Order Details].unitprice * [Order Details].quantity * (1-[Order Details].discount)) as 'total_price' from Orders right join [Order Details] on Orders.OrderID=[Order Details].OrderID right join Customers on Orders.CustomerID=Customers.CustomerID  group by [Order Details].OrderID,Customers.ContactName
--6
use library
select distinct lastname,firstname from member left join loanhist on member.member_no=loanhist.member_no where isbn is null 
intersect
select distinct lastname,firstname from member left join loan on member.member_no=loan.member_no where isbn is null order by lastname