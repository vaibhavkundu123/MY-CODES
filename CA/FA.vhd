library ieee;
use ieee.std_logic_1164.all;
entity fa is
port( a,b,cin: in std_logic;
   s,cout: out std_logic);
end fa;

architecture arch1 of fa is
begin
s<=(a xor b) xor cin;
cout<=(a and b) or (cin and (a xor b));
end arch1;
