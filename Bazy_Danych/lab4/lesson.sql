use joindb
select * from Sales
select * from Buyers
select Buyers.buyer_name,sales.qty from Buyers,Sales
select Buyers.buyer_name,sales.qty from Buyers,Sales where Buyers.buyer_id=Sales.buyer_id

select buyer_name,s.buyer_id,qty 
from Buyers as b inner join sales 
as s on b.buyer_id = s.buyer_id

use Northwind
select * from Products
select * from Suppliers
select ProductName,CompanyName from Products inner join Suppliers on Products.SupplierID=Suppliers.SupplierID
select Orders.CustomerID from Customers inner join Orders on Orders.CustomerID = Customers.CustomerID where year(OrderDate)>1996 group by Orders.CustomerID
select * from Orders

select companyname,customers.CustomerID,orderdate from Customers left outer join Orders on customers.CustomerID = orders.CustomerID

use library
select member.firstname,member.lastname,juvenile.birth_date from juvenile inner join member on member.member_no=juvenile.member_no
select distinct title.title from loan inner join title on title.title_no = loan.title_no

select * from loanhist

select title,loanhist.in_date,due_date,DATEDIFF("DAY",due_date,in_date)
as "days kept",fine_paid,fine_assessed from loanhist join title 
on title.title_no=loanhist.title_no where title='Tao Teh King' and DATEDIFF("DAY",due_date,in_date)>0

select reservation.isbn,member.firstname,member.middleinitial,member.lastname 
from member inner join reservation 
on reservation.member_no = member.member_no 
where 
member.firstname = 'Stephen' 
and member.middleinitial='A' 
and member.lastname = 'Graff'

use Northwind
select * from Customers join Orders on Orders.CustomerID=Customers.CustomerID
select ProductName,UnitPrice,CompanyName,Address,City 
from Products join Suppliers on Suppliers.SupplierID = Products.SupplierID 
where UnitPrice between 20 and 30


select ProductName, UnitsInStock,UnitsOnOrder 
from Products join Suppliers on Products.SupplierID=Suppliers.SupplierID 
where CompanyName = 'Tokyo Traders'

select ProductName, UnitsInStock, CompanyName,Phone
from Products join Suppliers on Products.SupplierID=Suppliers.SupplierID 
where UnitsInStock = 0


--HOMEWORK v1 (nie dzia³a)
select distinct Customers.CompanyName,Customers.Phone 
from Customers join Orders on Orders.CustomerID=Customers.CustomerID 
where not year(OrderDate) = 1997 order by CompanyName



--HOMEWORK v2 
select distinct Customers.CompanyName,Customers.Phone from Customers 
except select distinct Customers.CompanyName,Customers.Phone from Customers join Orders on Orders.CustomerID=Customers.CustomerID 
where year(OrderDate) = 1997 order by CompanyName
--HOMEWORK v3
select customers.customerid,orderdate from Customers left outer join orders on Orders.Customerid=Customers.customerid and YEAR(orderdate)=1997 where orderdate=NULL

