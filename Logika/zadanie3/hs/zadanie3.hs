--ghc 710
--Aleksander Mikucki
{-# LANGUAGE TypeOperators #-}

type A = (Int,Int)
type B = (Int,Bool)
type C = (Bool,Int)
type D = (Bool,Bool)

type a :\/: b = Either a b
type a :/\: b = (a,b)

impl_rozdz :: (A -> B) -> (A -> C) -> A -> B -> C
impl_rozdz a_wyn_b a_wyn_c a b = a_wyn_c(a)


impl_komp :: (A -> B) -> (B -> C) -> A -> C
impl_komp a_wyn_b b_wyn_c a = b_wyn_c(a_wyn_b(a))


impl_perm :: (A -> B -> C) -> B -> A -> C 
impl_perm a_wyn_b_wyn_c b a = a_wyn_b_wyn_c(a)(b)


impl_conj :: A -> B -> A :/\: B
impl_conj a b = (a,b)


conj_elim_l :: A :/\: B -> A 
conj_elim_l (a,b) = a


disj_intro_l :: A -> A :\/: B
disj_intro_l a = Left a --to œrednio ma sens

rozl_elim :: A :\/: B -> (A -> C) -> (B -> C) -> C 
rozl_elim (Left a) a_wyn_c b_wyn_c = a_wyn_c(a) --pattern matching na podstawie tego który typ siedzi w either
rozl_elim (Right b) a_wyn_c b_wyn_c = b_wyn_c(b)


diamencik :: (A -> B) -> (A -> C) -> (B -> C -> D) -> A -> D
diamencik a_wyn_b a_wyn_c b_wyn_c_wyn_d a = b_wyn_c_wyn_d(a_wyn_b(a))(a_wyn_c(a))


slaby_peirce :: ((((A -> B) -> A) -> A) -> B) -> B
slaby_peirce q = q (\w -> w (\e -> q (\k -> e)))


rozl_impl_rozdz :: (A :\/: B -> C) -> (A -> C) :/\: (B -> C)
rozl_impl_rozdz a_lub_b_wyn_c = ((\a_lub_b -> a_lub_b_wyn_c(Left a_lub_b)), (\a_lub_b -> a_lub_b_wyn_c (Right a_lub_b)))

 
rozl_impl_rozdz_odw :: (A -> C) :/\: (B -> C) -> A :\/: B -> C
rozl_impl_rozdz_odw (a_wyn_c,b_wyn_c) (Left a)  = a_wyn_c(a)
rozl_impl_rozdz_odw (a_wyn_c,b_wyn_c) (Right b) = b_wyn_c(b)


mycurry :: (A :/\: B -> C) -> A -> B -> C
mycurry a_i_b_wyn_c a b = a_i_b_wyn_c((a,b))


myuncurry :: (A -> B -> C) -> A :/\: B -> C
myuncurry a_wyn_b_wyn_c (a,b) = a_wyn_b_wyn_c(a)(b)


main = print $ "I can't believe that worked :o"
