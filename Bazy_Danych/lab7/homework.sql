--cw1
--zad1
use Northwind
select distinct Customers.CompanyName, Customers.Phone from Customers where CustomerID in (select distinct CustomerID from Orders where ShipVia = (select ShipperID from Shippers where Shippers.CompanyName='United Package') and YEAR(OrderDate)=1997)

select distinct Customers.CompanyName, Customers.Phone from Customers join Orders on Customers.CustomerID=Orders.CustomerID  join Shippers on Orders.ShipVia=Shippers.ShipperID where Shippers.CompanyName='United Package' and YEAR(OrderDate)=1997
--zad2
select distinct CompanyName, Phone from Customers where CustomerID 
in (select distinct CustomerID from Orders join [Order Details] 
on Orders.OrderID = [Order Details].OrderID where ProductID 
in (select distinct ProductID from Products where 
CategoryID = (select CategoryID from Categories where CategoryName = 'Confections')))

select distinct Customers.CompanyName, Customers.Phone
from Customers join Orders on Customers.CustomerID = Orders.CustomerID
join [Order Details] on [Order Details].OrderID = Orders.OrderID
join Products on Products.ProductID = [Order Details].ProductID
join Categories on Products.CategoryID = Categories.CategoryID where CategoryName = 'Confections'
--zad3
select distinct CompanyName, Phone from Customers where CustomerID 
not in (select distinct CustomerID from Orders join [Order Details] 
on Orders.OrderID = [Order Details].OrderID where ProductID 
in (select distinct ProductID from Products where 
CategoryID in (select CategoryID from Categories where CategoryName = 'Confections')))

select CompanyName from Customers left outer join Orders on Customers.CustomerID=Orders.CustomerID where OrderDate is null

select distinct Customers.CompanyName, Customers.Phone from Customers
except
select distinct Customers.CompanyName, Customers.Phone
from Customers left join Orders on Customers.CustomerID = Orders.CustomerID
left join [Order Details] on [Order Details].OrderID = Orders.OrderID
left join Products on Products.ProductID = [Order Details].ProductID
left join Categories on Products.CategoryID = Categories.CategoryID where CategoryName='Confections'
--cw2
--zad1
select ProductName,(select max(Quantity) from [Order Details] where [Order Details].ProductID = Products.ProductID) as maxQuantity from Products order by ProductName

select ProductName,max(Quantity) from [Order Details] join Products on [Order Details].ProductID=Products.ProductID group by ProductName order by ProductName

--zad2
select ProductName,UnitPrice from Products where UnitPrice < (select avg(UnitPrice) from [Order Details])

select Products.productname, Products.unitprice, avg(Products2.unitprice)
from Products cross join Products as Products2 group by Products.productname, Products.unitprice
having Products.unitprice < avg(Products2.unitprice)
--zad3
select ProductName from Products where UnitPrice < (select avg(UnitPrice) from Products where CategoryID = Products.CategoryID)

select Products.productname, Products.unitprice, avg(Products2.unitprice)
from Products cross join Products as Products2 group by Products.productname, Products.unitprice, Products.CategoryID
having Products.unitprice < avg(Products2.unitprice)
--cw3
--zad1
select ProductName, UnitPrice, 
(select avg(UnitPrice) from Products) as 'sredniacenawszystkich',
UnitPrice-(select avg(UnitPrice) from Products) as 'roznica'
from Products
--zad2
select ProductName, UnitPrice,
(select avg(UnitPrice) from Products where CategoryID = Products2.CategoryID),
(select avg(UnitPrice) from Products where CategoryID = Products2.CategoryID) - UnitPrice,
(select CategoryName from Categories where CategoryID=Products2.CategoryID)
from Products as Products2
--cw4
--zad1
select (select sum(UnitPrice * Quantity * (1 - Discount)) from [Order Details] where OrderID = 10250)
+ (select Freight from Orders where OrderID = 10250)

select Orders.Freight+ sum(([Order Details].UnitPrice*[Order Details].Quantity*(1-[Order Details].Discount))) 
from Orders 
join [Order Details] on [Order Details].OrderID=Orders.OrderID where Orders.OrderID=10250 group by Orders.Freight

--zad2
select (select sum(UnitPrice * Quantity * (1 - Discount)) from [Order Details] where OrderID = Orders.OrderID) + Freight as total, OrderID
from Orders

select Orders.Freight+ sum([Order Details].UnitPrice*[Order Details].Quantity*(1-[Order Details].Discount)),Orders.OrderID from Orders 
join [Order Details] on [Order Details].OrderID=Orders.OrderID group by Orders.OrderID, Orders.Freight
--- zad 3
select Customers.ContactName,Customers.Address from Customers where not exists (select OrderID from Orders where CustomerID = Customers.CustomerID and YEAR(OrderDate) = '1997')

select Customers.ContactName,Customers.Address, Orders.OrderDate from Customers left join Orders on Customers.CustomerID=Orders.CustomerID and Year(OrderDate)=1997 where OrderDate is null
 --- zad 4
 select distinct Products.ProductID, Products.ProductName from Products join [Order Details] on Products.ProductID= [Order Details].ProductID
 join Orders on [Order Details].OrderID = Orders.OrderID
 where exists (select ProductID from [Order Details]  join Orders as Orders2 on [Order Details].OrderID = Orders2.OrderID
 where ProductID = Products.ProductID and Orders2.CustomerID <> Orders.CustomerID) 
 
 select distinct Products.ProductID, Products.ProductName from Products join [Order Details] on Products.ProductID= [Order Details].ProductID
 join Orders on [Order Details].OrderID = Orders.OrderID cross join Orders as Orders2 where Orders.CustomerID <> Orders2.CustomerID
 --cw5
 --zad1
 use Northwind
select Employees.FirstName from Employees where EmployeeId = (select top 1 (select Orders.EmployeeID, sum([Order Details].unitprice * [Order Details].quantity * (1-[Order Details].discount)) as 'total_price'
from Orders join [order details] on Orders.orderid = [Order Details].orderid group by EmployeeID) order by 'total_price' desc)


select Employees.lastname, Employees.firstname, sum([Order Details].unitprice * [Order Details].quantity * (1-[Order Details].discount)) as 'total_price'
from employees join orders on Employees.employeeid = Orders.employeeid join [order details] on Orders.orderid = [Order Details].orderid
group by Employees.lastname, Employees.firstname,Employees.employeeid
--zad2
select top 1 Employees.lastname, Employees.firstname, sum([Order Details].unitprice * [Order Details].quantity * (1-[Order Details].discount)) as 'total_price'
from employees join orders on Employees.employeeid = Orders.employeeid and year(Orders.OrderDate)=1997 join [order details] on Orders.orderid = [Order Details].orderid
group by Employees.lastname, Employees.firstname,Employees.employeeid
order by 3 desc
--zad3
--a)
select Employees.lastname, Employees.firstname, sum([Order Details].unitprice * [Order Details].quantity * (1-[Order Details].discount)) as 'total_price'
from employees join orders on Employees.employeeid = Orders.employeeid join [order details] on Orders.orderid = [Order Details].orderid
join Employees as Employees2 on Employees2.ReportsTo = Employees.ReportsTo
group by Employees.lastname, Employees.firstname,Employees.employeeid
--b)
select Employees.lastname, Employees.firstname, sum([Order Details].unitprice * [Order Details].quantity * (1-[Order Details].discount)) as 'total_price'
from employees join orders on Employees.employeeid = Orders.employeeid join [order details] on Orders.orderid = [Order Details].orderid
left join Employees as Employees2 on Employees2.ReportsTo = Employees.ReportsTo where Employees.ReportsTo is null
group by Employees.lastname, Employees.firstname,Employees.employeeid

 