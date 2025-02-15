library ieee;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_1164.all;

entity restoring_division_4bit is
port (d : in std_logic_vector(3 downto 0); 
	m : in std_logic_vector(3 downto 0);
	q : out std_logic_vector(3 downto 0);
        r : out std_logic_vector(3 downto 0));
end restoring_division_4bit;

architecture arch1 of restoring_division_4bit is
begin
process(d, m)
variable ac :std_logic_vector(8 downto 0);
variable m1 :std_logic_vector(4 downto 0);
begin
ac(8 downto 4) := "00000";
ac(3 downto 0) := d;
m1 := '0' & m;
for i in 1 to 4 loop
ac := ac(7 downto 0) & 'U';
ac(8 downto 4) := ac(8 downto 4) - m1;
if ac(8) = '0' then
ac(0) := '1';
else
ac(0) := '0';
ac(8 downto 4) := ac(8 downto 4) + m1;
end if;
end loop;
q <= ac(3 downto 0);
r <= ac(7 downto 4);
end process;
end arch1;
