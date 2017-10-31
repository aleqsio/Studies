use library
--zad 1
select title_no, title from title
select title_no, title from title where (title_no=10)
select member_no,fine_assessed from loanhist where (fine_assessed between 8 and 9)
select title_no, author from title where (author in ('Charles Dickens','Jane Austen'))
--zad 2
select title_no,title from title where (title like '%adventures%')
select member_no,fine_assessed,fine_paid,fine_waived from loanhist where (COALESCE(fine_assessed,0) > (COALESCE(fine_paid,0) + COALESCE(fine_waived,0)))
select distinct city,state from adult
--zad 3
select title from title order by title
select member_no,isbn,fine_assessed,fine_assessed*2 as 'double fine' from loanhist where (COALESCE(fine_assessed,0) >0)
select (firstname+middleinitial+lastname) as 'email_name' from member where (lastname='Anderson')
select (LOWER(firstname+middleinitial+SUBSTRING(lastname,1,2))) as 'email_name' from member where (lastname='Anderson')
--zad 4
select * from title
select 'The title is: '+title+', title number '+CONVERT(varchar(10),title_no) as 'title' from title