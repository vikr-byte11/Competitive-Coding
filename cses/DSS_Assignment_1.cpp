
/*
Name:Vikram Singh
Roll no:IIT2019213
Architecture:                    x86_64
CPU op-mode(s):                  32-bit, 64-bit
Byte Order:                      Little Endian
Address sizes:                   39 bits physical, 48 bits virtual
CPU(s):                          4
On-line CPU(s) list:             0-3
Thread(s) per core:              2
Core(s) per socket:              2
Socket(s):                       1
NUMA node(s):                    1
Vendor ID:                       GenuineIntel
CPU family:                      6
Model:                           69
Model name:                      Intel(R) Core(TM) i5-4210U CPU @ 1.70GHz
Stepping:                        1
CPU MHz:                         800.000
CPU max MHz:                     2700.0000
CPU min MHz:                     800.0000
BogoMIPS:                        3392.00
Virtualization:                  VT-x
L1d cache:                       64 KiB
L1i cache:                       64 KiB
L2 cache:                        512 KiB
L3 cache:                        3 MiB
NUMA node0 CPU(s):               0-3
Vulnerability Itlb multihit:     KVM: Mitigation: VMX disabled
Vulnerability L1tf:              Mitigation; PTE Inversion; VMX conditional cach
                                 e flushes, SMT vulnerable
Vulnerability Mds:               Mitigation; Clear CPU buffers; SMT vulnerable
Vulnerability Meltdown:          Mitigation; PTI
Vulnerability Spec store bypass: Mitigation; Speculative Store Bypass disabled v
                                 ia prctl and seccomp
Vulnerability Spectre v1:        Mitigation; usercopy/swapgs barriers and __user
                                  pointer sanitization
Vulnerability Spectre v2:        Mitigation; Full generic retpoline, IBPB condit
                                 ional, IBRS_FW, STIBP conditional, RSB filling
Vulnerability Srbds:             Mitigation; Microcode
Vulnerability Tsx async abort:   Not affected
Flags:                           fpu vme de pse tsc msr pae mce cx8 apic sep mtr
                                 r pge mca cmov pat pse36 clflush dts acpi mmx f
                                 xsr sse sse2 ss ht tm pbe syscall nx pdpe1gb rd
                                 tscp lm constant_tsc arch_perfmon pebs bts rep_
                                 good nopl xtopology nonstop_tsc cpuid aperfmper
                                 f pni pclmulqdq dtes64 monitor ds_cpl vmx est t
                                 m2 ssse3 sdbg fma cx16 xtpr pdcm pcid sse4_1 ss
                                 e4_2 movbe popcnt tsc_deadline_timer aes xsave 
                                 avx f16c rdrand lahf_lm abm cpuid_fault epb inv
                                 pcid_single pti ssbd ibrs ibpb stibp tpr_shadow
                                  vnmi flexpriority ept vpid ept_ad fsgsbase tsc
                                 _adjust bmi1 avx2 smep bmi2 erms invpcid xsaveo
                                 pt dtherm ida arat pln pts md_clear flush_l1d

*/

#include <bits/stdc++.h>
#include <pthread.h>
#include <chrono>
using namespace std::chrono;
using namespace std;
#define MT 16
int sum[MT] = {0};
int pt = 0;
double *a = new double[1024];
void *s_a(void *arg)
{

    int tt = pt;
    pt++;
    for (int i = tt * (1024 / 4); i < (tt + 1) * (1024 / 4); i++)
        sum[tt] += a[i];
}

int main()
{
    auto st = high_resolution_clock::now();
    int n = 1024;
    for (int i = 0; i < n; i++)
        a[i] = i;
    double ts = 0;
    for (int i = 0; i < n; i++)
        ts += a[i];
    double f_s = (double)n * (n - 1) / 2;
    pthread_t th[MT];
    for (int i = 0; i < MT; i++)
        pthread_create(&th[i], NULL, s_a, (void *)NULL);
    for (int i = 0; i < MT; i++)
        pthread_join(th[i], NULL);
    double l_s = 0;
    for (int i = 0; i < MT; i++)
        l_s += sum[i];
    cout << "N: " << n << endl;
    cout << "Loop Sum: " << l_s << endl;
    cout << "Formula Sum: " << f_s << endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - st);
    cout << duration.count() << endl;
    return 0;
}