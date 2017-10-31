sqr :: Double -> Double
sqr x = x*x
absInt :: Int -> Int
absInt n | n > 0 = n
         | n < 0 = -n
sgn :: Int -> Int
sgn n | n<0 = -1
	  | n==0 = 0
	  | otherwise = 1
min3Int :: (Int, Int, Int) -> Int -- min (1,2,3)=1, min (1,1,3)=1
min3Int (a,b,c) | a<b && b<c = a | b<a && a<c =b | c<a && a<b =c