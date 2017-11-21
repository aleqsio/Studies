use joindb

select buyer_name, prod_name, qty FROM buyers inner join sales on buyers.buyer_id = sales.buyer_id inner join Produce on sales.prod_id  = Sales.prod_id

use Northwind
select Suppliers.Address,ProductName,UnitPrice from Suppliers join Products on Products.SupplierID=Suppliers.SupplierID join Categories on Categories.CategoryID=Products.ProductID where Categories.CategoryName='Meat/Poultry' and UnitPrice between 20 and 30
select ProductName,UnitPrice,Suppliers.CompanyName from Suppliers join Products on Products.SupplierID=Suppliers.SupplierID join Categories on Categories.CategoryID=Products.ProductID where Categories.CategoryName='Confections'
select Customers.ContactName,Customers.Phone from Customers join Orders on Customers.CustomerID=Orders.CustomerID join Shippers on Orders.ShipVia=ShipperID where Shippers.CompanyName = 'United Package'
select Customers.ContactName,Customers.Phone from Customers join Orders on Customers.CustomerID=Orders.CustomerID join [Order Details] on Orders.OrderID=[Order Details].OrderID join Products on Products.ProductID=[Order Details].ProductID join Categories on Categories.CategoryID=Products.CategoryID where CategoryName ='Confections'

use library
select CONCAT(member.firstname,member.middleinitial,member.lastname) as 'name', birth_date,street,city,state,zip 
from juvenile join member on juvenile.member_no=member.member_no join adult on adult_member_no=adult.member_no

select CONCAT(member.firstname,member.middleinitial,member.lastname) as 'name', birth_date,street,city,state,zip,CONCAT(member2.firstname,member2.middleinitial,member2.lastname) as 'adultname' 
from juvenile join member on juvenile.member_no=member.member_no join adult on juvenile.adult_member_no=adult.member_no join member as member2 on member2.member_no=adult.member_no

use Northwind
select CONCAT(e.FirstName,e.LastName,' ',e.EmployeeID) as 'szef',CONCAT(e2.FirstName,e2.LastName) as 'podw³' from Employees as e join Employees as e2 on e2.ReportsTo=e.EmployeeID
select CONCAT(e.FirstName,e.LastName,' ',e.EmployeeID) as 'szef',e2.EmployeeID from Employees as e left join Employees as e2 on e2.ReportsTo=e.EmployeeID where e2.EmployeeID IS NULL

use library
select member.firstname,member.lastname,member.member_no,COUNT(*) as'childcnt' 
from adult join member on adult.member_no=member.member_no join
juvenile on member.member_no=juvenile.adult_member_no 
where adult.city='AZ'
group by member.firstname,member.lastname,member.member_no having COUNT(*) >=2