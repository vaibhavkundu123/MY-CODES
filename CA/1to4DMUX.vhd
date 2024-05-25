library ieee;
use ieee.std_logic_1164.all;
entity dmux1 is
port(O:in std_logic;
	S:in std_logic_vector(1 downto 0);
	I:out std_logic_vector(3 downto 0));
end dmux1;

architecture arch1 of dmux1 is
begin
process(S,O)
begin
I <= "UUUU";
case S is
when "00" => I(0) <= O;
when "01" => I(1) <= O;
when "10" => I(2) <= O;
when "11" => I(3) <= O;
when Others => I <= "UUUU";
end case;
end Process;
end arch1;