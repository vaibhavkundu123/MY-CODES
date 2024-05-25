library ieee;
use ieee.std_logic_1164.all;
entity mux1 is
port( I:in std_logic_vector(3 downto 0);
	S:in std_logic_vector(1 downto 0);
	O:out std_logic);
end mux1;

architecture arch1 of mux1 is
begin
process(I,S)
begin
case S is
when "00" => O <= I(0);
when "01" => O <= I(1);
when "10" => O <= I(2);
when "11" => O <= I(3);
when Others => O <= 'U';
end case;
end Process;
end arch1;