library ieee;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_1164.all;

entity multiplier_4bit is
port (m : in std_logic_vector(3 downto 0); 
	q : in std_logic_vector(3 downto 0);
        r : out std_logic_vector(7 downto 0));
end multiplier_4bit;

architecture arch1 of multiplier_4bit is
begin
process(m, q)
variable ac :std_logic_vector(8 downto 0);
variable mulp :std_logic_vector(4 downto 0);
begin
ac(8 downto 4) := "00000";
ac(3 downto 0) := q;
mulp := '0' & m;
for i in 1 to 4 loop
if ac(0) = '1' then
ac(8 downto 4) := ac(8 downto 4) + mulp;
end if;
ac := '0' & ac(8 downto 1);
end loop;
r <= ac(7 downto 0);
end process;
end arch1;
