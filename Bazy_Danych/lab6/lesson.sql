--nazwê cenê, sredni¹ cene, róznice
use Northwind
select ProductName,UnitPrice,(select avg(UnitPrice) from Products) as 'avg',(UnitPrice-(select avg(UnitPrice) from Products)) as'difference' from Products
--select orderid,customerid from orders as or1 where 20 < (select quantity
select * from orders join [Order Details] on Orders.OrderID=[Order Details].OrderID where ProductID=23 and Quantity>20

select ProductName,UnitPrice,CategoryID from Products where UnitPrice > (select avg(UnitPrice) from Products as P where P.CategoryID = Products.CategoryID)
select Products.ProductName,Products.UnitPrice,Products.CategoryID,p2.CategoryID from Products join Products as p2 on Products.CategoryId = p2.CategoryID group by Products.CategoryID having Products.UnitPrice > AVG(p2.CategoryID)
