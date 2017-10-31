use Northwind
select sum(UnitPrice*Quantity-Discount) as 'Price',OrderId from [Order Details] group by OrderID order by 1 desc
select top 10 sum(UnitPrice*Quantity-Discount) as 'Price',OrderId from [Order Details] group by OrderID order by 1 desc
select distinct top 10 sum(UnitPrice*Quantity-Discount) as 'Price',OrderId from [Order Details] group by OrderID order by 1 desc
--zad2
select sum(quantity) from [Order Details] where productid < 3 group by productid
select sum(quantity) from [Order Details] group by productid
select sum(quantity) from [Order Details] group by productid having sum(quantity)>250
select UnitsOnOrder from Products where ProductID<3
--zad3
select OrderID,ProductID,sum(Quantity) as 'Quantitysum' from [Order Details] group by ProductID,OrderID with rollup
select OrderID,ProductID,sum(Quantity) as 'Quantitysum' from [Order Details] group by ProductID,OrderID with rollup having ProductID=50
--Kolumna null w danym polu oznacza, �e wyliczona warto�� jest sum� wszystkich rz�d�w o dowolnej warto�ci tego pola, kt�re maj� zgodne pozosta�e pola
select GROUPING(OrderID) as 'A',OrderID,Grouping(ProductID) as'B',ProductID,sum(Quantity) as 'Quantitysum' from [Order Details] group by ProductID,OrderID with cube
--Te, kt�re w polu grouping maj� warto�� 1.
--Pierwsza kolumna A oznacza grupowanie po numerze zam�wienia, a druga B po numerze produktu
