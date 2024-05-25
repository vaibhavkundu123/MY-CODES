library ieee;
use ieee.std_logic_1164.all;

entity decoder1 is
    Port ( a,b,enable : in std_logic;
           z : out std_logic_vector(3 downto 0));
end decoder1;

architecture arch1 of decoder1 is
begin
process(a,b,enable)
variable abar,bbar : std_logic;
begin
abar := not a;
bbar := not b;
if enable = '1' then
z(0) <= abar and bbar;
z(1) <= abar and b;
z(2) <= a and bbar;
z(3) <= a and b;
else
z <= "UUUU";
end if;
end process;
end arch1;
