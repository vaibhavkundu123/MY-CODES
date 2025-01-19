echo "---------------------------------"
echo "     System Information"
echo "---------------------------------"

# Display the hostname
echo "Hostname: $(hostname)"
echo

# Display the operating system and version
echo "Operating System and Version:"
echo "$(uname -o) $(lsb_release -d | cut -f2)"
echo

# Display the kernel version
echo "Kernel Version: $(uname -r)"
echo

# Display the system uptime
echo "System Uptime: $(uptime -p)"
echo

# Display the memory usage with separate details
echo "Memory Usage:"
total_memory=$(free -h | awk '/Mem/ {print $2}')
used_memory=$(free -h | awk '/Mem/ {print $3}')
free_memory=$(free -h | awk '/Mem/ {print $4}')
shared_memory=$(free -h | awk '/Mem/ {print $5}')
buffer_cache=$(free -h | awk '/Mem/ {print $6}')
available_memory=$(free -h | awk '/Mem/ {print $7}')

echo "  Total memory     = $total_memory"
echo "  Used memory      = $used_memory"
echo "  Free memory      = $free_memory"
echo "  Shared memory    = $shared_memory"
echo "  Buffers/cache    = $buffer_cache"
echo "  Available memory = $available_memory"
echo

# Display the disk usage for C, D, and E partitions only
echo "Disk Usage for C, D, and E:"
df -h | grep -E 'Mounted on'
df -h | grep -E '/mnt/c|/mnt/d|/mnt/e'
echo

echo "---------------------------------"
echo "      End of System Info"
echo "---------------------------------"

