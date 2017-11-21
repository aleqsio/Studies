use library
select member.firstname,member.lastname,member.member_no,COUNT(*) as'childcnt' 
from adult join member on adult.member_no=member.member_no join
juvenile on member.member_no=juvenile.adult_member_no 
where adult.state='AZ'
group by member.firstname,member.lastname,member.member_no having COUNT(*) >=2


select member.firstname,member.lastname,member.member_no,COUNT(*) as'childcnt' 
from adult join member on adult.member_no=member.member_no join
juvenile on member.member_no=juvenile.adult_member_no 
where adult.state='AZ'
group by member.firstname,member.lastname,member.member_no having COUNT(*) >=2
union
select member.firstname,member.lastname,member.member_no,COUNT(*) as'childcnt' 
from adult join member on adult.member_no=member.member_no join
juvenile on member.member_no=juvenile.adult_member_no 
where adult.state='CA'
group by member.firstname,member.lastname,member.member_no having COUNT(*) >=3
 
use Northwind
select CategoryName,sum(UnitsOnOrder) from Orders join [Order Details] on [Order Details].OrderID=Orders.OrderID join Products on [Order Details].ProductID=Products.ProductID join Categories on Categories.CategoryID=Products.CategoryID group by Categories.CategoryName

--zad1
select  Customers.CompanyName, sum([Order Details].Quantity) as 'Quantity' from Customers join Orders
on Customers.CustomerID = Orders.CustomerID join [Order Details] 
on Orders.OrderID = [Order Details].OrderID
group by Customers.CompanyName             

--zad2
select  Customers.CompanyName, sum([Order Details].Quantity) as 'Quantity' from Customers join Orders
on Customers.CustomerID = Orders.CustomerID join [Order Details] 
on Orders.OrderID = [Order Details].OrderID
group by Customers.CompanyName
having sum([Order Details].Quantity) > 250
--zad3
select Orders.OrderID, Customers.CompanyName, sum([Order Details].Quantity * [Order Details].UnitPrice * (1 - [Order Details].Discount)) as 'price'
from  Customers join Orders on Customers.CustomerID = Orders.CustomerID join [Order Details] on Orders.OrderID = [Order Details].OrderID            
group by Orders.OrderID, Customers.CompanyName
--zad4
select Orders.OrderID, Customers.CompanyName, sum([Order Details].Quantity * [Order Details].UnitPrice * (1 - [Order Details].Discount)) as 'price'
from  Customers join Orders on Customers.CustomerID = Orders.CustomerID join [Order Details] on Orders.OrderID = [Order Details].OrderID            
group by Orders.OrderID, Customers.CompanyName
having sum([Order Details].Quantity) > 250
--zad5
select Orders.OrderID, Customers.CompanyName, sum([Order Details].Quantity * [Order Details].UnitPrice * (1 - [Order Details].Discount)) as 'price', Employees.FirstName,Employees.LastName
from  Customers join Orders on Customers.CustomerID = Orders.CustomerID join [Order Details] on Orders.OrderID = [Order Details].OrderID       
join Employees on Orders.EmployeeID = Employees.EmployeeID
group by Orders.OrderID, Customers.CompanyName, Employees.LastName, Employees.FirstName     
having sum([Order Details].Quantity) > 250

--#cw2
--zad1
select Categories.categoryname, sum([Order Details].quantity) as'qnt_sum' from categories join products on Categories.categoryid = Products.categoryid
join [order details] on Products.productid = [Order Details].productid
group by Categories.categoryid, Categories.categoryname
--zad2
select Categories.categoryname, sum([Order Details].quantity * [Order Details].unitprice * (1 - [Order Details].discount))  as'price_sum' from categories join products on Categories.categoryid = Products.categoryid
join [order details] on Products.productid = [Order Details].productid
group by Categories.categoryid, Categories.categoryname
--zad3
--a)
select Categories.categoryname, sum([Order Details].quantity * [Order Details].unitprice * (1 - [Order Details].discount)) as 'total_price'
from categories join products on Categories.categoryid = Products.categoryid 
join [order details]on Products.productid = [Order Details].productid
group by Categories.categoryname
order by 2

select Categories.categoryname, sum([Order Details].quantity * [Order Details].unitprice * (1 - [Order Details].discount)) as 'total_price'
from categories join products on Categories.categoryid = Products.categoryid 
join [order details]on Products.productid = [Order Details].productid
group by Categories.categoryname
order by sum([Order Details].Quantity)
--#cw3
--zad1
select shippers.companyname, count(orders.orderid) as 'order_count'
from Shippers join Orders on Shippers.ShipperID = Orders.ShipVia
group by shippers.companyname, shippers.shipperid
order by shippers.companyname
--zad2
select top 1 shippers.companyname, count(orders.orderid) as 'order_count'
from Shippers join Orders on Shippers.ShipperID = Orders.ShipVia and year(orders.shippeddate) = 1997
group by shippers.companyname order by 2 desc
--zad3
select top 1 employees.FirstName, employees.LastName, count(orders.orderid) as 'order_count'
from employees join orders on employees.employeeid = orders.employeeid and year(orders.shippeddate) = 1997
group by employees.lastname, employees.firstname order by 3 desc
--#cw4
--zad1
use Northwind
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
