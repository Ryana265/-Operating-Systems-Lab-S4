echo "Enter the limit"
read n;
a=0;
b=1;
echo "The Fibonacci series is";
for((i=0;i<n;i++))
do
 echo "$a";
 c=$((a+b));
 a=$b;
 b=$c;
 
 done
