library ieee;
use ieee.std_logic_1164.all;
entity fa1 is
port( a,b,cin: in std_logic;
   s,cout: out std_logic);
end fa1;

architecture arch1 of fa1 is
begin
process(a,b,cin)
variable sw : std_logic_vector(2 downto 0);
begin
sw(0) := cin;
sw(1) := a;
sw(2) := b;
case sw is
when "000" => s <= '0';
		cout <= '0';
when "001" => s <= '1';
		cout <= '0';
when "010" => s <= '1';
		cout <= '0';
when "011" => s <= '0';
		cout <= '1';
when "100" => s <= '1';
		cout <= '0';
when "101" => s <= '0';
		cout <= '1';
when "110" => s <= '0';
		cout <= '1';
when "111" => s <= '1';
		cout <= '1';
when Others => s <= 'U';
		cout <= 'U';
end case;
end process;
end arch1;
