use Northwind
select sum(Orders.Freight+[Order Details].UnitPrice*[Order Details].Quantity*(1-[Order Details].Discount)) 
from Orders 
join [Order Details] on [Order Details].OrderID=Orders.OrderID 
where Orders.OrderID=10250

select (select sum(Orders.Freight) from Orders where OrderID=10250)+sum([Order Details].UnitPrice*[Order Details].Quantity*(1-[Order Details].Discount)) 
from [Order Details]
where [Order Details].OrderID=10250