use Northwind

select ContactName, Address from Customers where (City = 'London')
select ContactName, Address, Country from Customers where (Country = 'France' or Country = 'Spain')
select * from Products
select * from Categories
select * from Customers
select * from Suppliers
select * from Employees
/*zad 3*/select ProductName, UnitPrice from Products where (UnitPrice <30 and UnitPrice > 20)
/*zad 4*/select ProductName, UnitPrice from Products where (CategoryID = (Select CategoryID from Categories where CategoryName LIKE '%Meat%'))
/*zad 5*/select ProductName from Products where  (SupplierID = (SELECT SupplierID FROM Suppliers where (CompanyName = 'Tokyo Traders')))
/*zad 6*/select ProductName from Products where(UnitsInStock <=0 and Discontinued = 0) 

select * from Employees where (Country = 'USA')
select * from Employees where (HireDate > 1950-01-01)
select * from Employees where (HireDate > 1950-01-01 and city = 'London' )

select CustomerID from Customers where CompanyName like '%Restaurant'
select * from Products where QuantityPerUnit like '%bottles%'
select * from Employees where (LastName like '[B-L]%')
select * from Employees where (LastName like '[B,L]%')
select CategoryName from Categories where (Description like '%,%')
select * from Customers where ContactName like '%Store%'
SELECT productid, productname, supplierid, unitprice FROM products WHERE (productname LIKE 'T%' OR productid = 46) AND (unitprice > 16) 
SELECT productid, productname, supplierid, unitprice FROM products WHERE productname LIKE 'T%' OR productid = 46 AND unitprice > 16
select ProductName, UnitPrice from Products where (UnitPrice not between 10 AND 20)


select ContactName, Address, Country from Customers where (Country in ('JAPAN' , 'GERMANY'))
select * from Customers where Fax is Null
select * from Orders where (ShipCountry = 'Argentina' and (ShippedDate is null or ShippedDate > getDate()))

select productid, productname, unitprice,CategoryID from products order by CategoryID, unitprice desc
select productid, productname, unitprice,CategoryID from products order by 4, 3 desc
select  Country, ContactName from Customers order by  Country, CompanyName asc 
select CategoryID, ProductName, UnitPrice from Products order by CategoryID,UnitPrice desc
select distinct Country from Customers
select distinct Country Kraj, ContactName as Imie from Customers
select Country,'Kraj klienta', ContactName as Imie from Customers
select ProductName, unitprice, unitprice *1.05 as newunitprice from Products 
select firstname,lastname, firstname + ':' + lastname as imienazwisko from Employees

use library
select * from Loanlist 