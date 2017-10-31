use Northwind
select top 5 ProductID,OrderID,Quantity from [Order Details] order by Quantity desc
select * from Employees
select count(ReportsTo) from Employees
select avg(UnitPrice) from Products
select avg(UnitPrice) from Products where (UnitPrice>100)
select count(*) from Products where (UnitPrice >10 and UnitPrice<20)
select max(UnitPrice) from Products where (UnitPrice<20)
select max(UnitPrice), min(UnitPrice), avg(UnitPrice) from Products where (QuantityPerUnit like '%bottles%')
--select * from Products where (UnitPrice>avg(UnitPrice))
select * from Products where (UnitPrice>(select avg(UnitPrice) from Products))
select SUM(UnitPrice*Quantity*(1-Discount)) from [Order Details] where OrderID = 10250
select * from orderhist
select orderid,sum(quantity) as 'order quantinty' from orderhist group by orderid
--zad
select max(UnitPrice) from [Order Details] group by OrderID
select max(UnitPrice) as'max',min(UnitPrice) as 'min' from [Order Details] group by OrderID
select * from [Order Details]
select count(*) from Orders group by ShipVia
select CompanyName from Suppliers where (SupplierID = (select top 1 ShipVia as 'cnt' from Orders where (year(ShippedDate)=1997) group by ShipVia order by count(*) desc))
select top 1 ShipVia,count(*) as 'cnt' from Orders where (year(ShippedDate)=1997) group by ShipVia order by cnt desc
select productId, SUM(quantity) as 'total_quant' from [Order Details] group by productid having sum(quantity) >15
select OrderID from [Order Details] group by OrderID having count(*) >5
select * from Orders
select CustomerID,count(*) as 'Order count',sum(Freight) as 'Freight sum' from Orders where (year(ShippedDate)=1998) group by CustomerID having COUNT(*)>8  order by sum(Freight) desc
select sum(quantity) from orderhist
select productid,null,sum(quantity) from orderhist group by productid
select productId, orderId,sum(quantity) from orderhist group by productId,orderId
select productId,GROUPING(productId), orderId,sum(quantity) from orderhist group by productId,orderId with cube
--{ --< --E --# --$ --( --