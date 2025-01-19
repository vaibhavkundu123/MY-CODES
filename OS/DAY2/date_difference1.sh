echo "Enter the 1st date(dd/mm/yyyy)"
read date1
echo $date1 > f1.txt
echo "Enter the 2nd date(dd/mm/yyyy)"
read date2
echo $date2 > f2.txt
d1=$(cut -d "/" -f1 f1.txt)
m1=$(cut -d "/" -f2 f1.txt)
y1=$(cut -d "/" -f3 f1.txt)
d2=$(cut -d "/" -f1 f2.txt)
m2=$(cut -d "/" -f2 f2.txt)
y2=$(cut -d "/" -f3 f2.txt)
if [ $y1 -lt $y2 ] 
then
t=$y1
y1=$y2
y2=$t
t=$m1
m1=$m2
m2=$t
t=$d1
d1=$d2
d2=$t
fi
if [ $d1 -lt $d2 ] 
then
dd=$((d1 + 30 - d2))
m1=$((m1 - 1))
else
dd=$((d1 - d2))
fi
if [ $m1 -lt $m2 ] 
then
dm=$((m1 + 12 - m2))
y1=$((y1 - 1))
else
dm=$((m1 - m2))
fi
dy=$((y1 - y2))
echo "Difference between the dates $date1 and $date2 is $dy years, $dm months and $dd days"
