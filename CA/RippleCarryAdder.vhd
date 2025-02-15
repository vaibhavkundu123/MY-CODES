library ieee;
use ieee.std_logic_1164.all;
entity ra is
port( a,b:in std_logic_vector(3 downto 0);
	s:out std_logic_vector(3 downto 0);
	crain:in std_logic;
	craout:out std_logic);
end ra;

architecture arch1 of ra is
component fa is
port( af,bf,cin:in std_logic;
   sf,cout: out std_logic);
end component;
signal sig: std_logic_vector(2 downto 0); 
begin
x1: fa port map(a(0),b(0),crain,s(0),sig(0));
x2: fa port map(a(1),b(1),sig(0),s(1),sig(1));
x3: fa port map(a(2),b(2),sig(1),s(2),sig(2));
x4: fa port map(a(3),b(3),sig(2),s(3),craout);
end arch1;
