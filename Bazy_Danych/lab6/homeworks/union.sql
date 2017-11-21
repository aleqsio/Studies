use library
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
 