# GOSP = Giveda® Open Source Project   
最容易理解的GUI框架，史上最简单，没有之一。   
example效果演示：   
![在doc/images/目录下](docs/images/DVB_768x432.gif)

![在doc/images/目录下](docs/images/DVB_edit_chnl_768x432.gif)

![在doc/images/目录下](docs/images/DVB_mainMenu_768x432_png.gif)

https://gitee.com/giveda/GOSP/tree/master/docs/images/DVB_768x432.gif  
https://gitee.com/giveda/GOSP/tree/master/docs/images/DVB_768x432_large.gif  
https://gitee.com/giveda/GOSP/tree/master/docs/images/DVB_edit_chnl_768x432.gif  
https://gitee.com/giveda/GOSP/tree/master/docs/images/DVB_mainMenu_768x432_png.gif  


# 一、简介和概述  
最容易理解的GUI框架，史上最简单，没有之一。   
  **2019-06-03，发表v1.0，版本代号为：沉默的蓝色幽灵。**    

Qt是芬兰人做的一个优秀的c++开发框架，API简单易用、远远超越了那些还在使用win32API&callback的同类产品。  
2018年，Qt公司内部立项了一个将Qt移植到MCU的研发新项目，资源占用情况如下：  
*) ROM占用情况：从6MB到13MB  
*) RAM占用情况：从4MB到10MB  
 **综上，Qt实在太庞大了！基于上述原因，在汲取了Qt精华的基础上，我做了这个软件。本软件在尊重Qt知识产权的前提下，尽量提供类似Qt的API接口，仅需要几百KB的RAM和ROM，能运行在Qt不支持的低性能领域。**    

  **如下功能处于筹划过程，视情况而定。**   
目前市场上常见的RTOS有如下：FreeRTOS、Vxworks、ReWorks、DeltaOS、SylixOS、华为liteOS、阿里AliOS、RT-Thread、RTEMS等，这些RTOS可以像linux/windows一样实现远程桌面吗？GOSP在筹划一个能够在RTOS上实现远程桌面的技术方案。  
在这里，我们首先要区分界面和桌面的关系，图形界面的含义非常广泛，几乎涵盖了所有的计算机信息展示界面。而桌面则是基于界面的概念，将一些普遍适用的常用基本功能打包在一起，方便二次开发，避免重复开发，我们则称之为桌面环境。  
在嵌入式领域，一个嵌入式远程桌面，我想更多的是指能够通过远程界面来实现对电子设备的交互控制吧。  
2019年之前，RTOS+远程桌面这样的功能是不可以的（如果用VNC技术是有很大缺陷和性能问题的）。我比较认可这个功能，我觉得这个功能非常实用，于是做了一个适用于RTOS的、高性能的远程桌面方案实现，把原本不能实现的功能给实现了，把原本VNC实现的不好的功能做出了更好更高效的实现。  **这个位于GOSP筹划中的软件方案可以在低性能计算设备（比如MCU）上替代VNC，在低性能计算设备上提供比VNC高效很多的远程界面显示与设备远程控制。**   

参考文献：  
http://blog.qt.io/cn/2018/08/15/qt_on_microcontrollers_mcu/  
http://giveda.com/


# 二、主要特色

* 史上最容易理解的GUI框架，史上最简单，没有之一。   
* 100%使用图片来实现个性化的控件和界面。（见下文的截图）   
* 提供了类似Qt的API，未来可提供基于qt creator的集成开发环境。  
* 基于别具一格的Giveda信号槽技术，各个模块代码之间无耦合。  
* 无耦合的代码，史上最容易复用，没有之一。  


# 三、许可协议  
  **你需要认真阅读如下软件授权协议，知情你的权利与义务：**         
*) 这是一个开源软件，你可以自由修改；我们希望它有用，但不提供质量保证（哪怕是隐含的或显而易见的质量保证）。虽然不提供质量保证，但并不意味着你能利用此点去侵害我们的商誉；如果需要质量保证，你可以购买商业版本。作为著作权人（以下简称我们），我们已经尽到了告知义务。一旦发现有人侵犯或者试图侵犯我们商誉，我们必将利用行政和法律手段死磕到底。   
*) 除了法律允许免费使用的情形，任何用到本软件全部或部分代码的行为，都需要向我们付费购买许可。   
*) 除非交易双方在《许可合同》中另有约定，否则的话，对本软件的任何修改、任何基于本软件全部或部分代码的衍生品、任何基于本软件全部或部分代码开发得到的作品、（通过任何形式）引用了本软件全部或部分代码的作品等都需要及时向我们定向开源，并同时向我们授权，允许我们以此相同协议对外公开以上软件代码和/或作品，允许我们自由使用以上软件代码和/或作品，允许我们将其授权给我们的客户进行自由使用。基于此，为了保护你的权益，你应当及时与我方商谈、签订《许可合同》。及时主动联系我方商谈签订《许可合同》是你的义务。   
*)  **商业许可实行按年对公司（老板）收费。主动联系我们并付费的价格为市场价格。被人举报的被动付费价格为惩罚性价格（市场价格的10倍）。**     
*)  **举报者可获得不低于成交额30%的现金奖励。**       
*)  **软件工程师是我们最尊敬的合作伙伴，他们能免费得到技术支持。**   
*) 中国的出口法律和法规适用于我们的发行版，并且随着产品和技术再出口到其它地区依旧保持有效。我们保留禁止任一用户使用以上开源软件的权利。  
*) 解释权归我方所有。因你方违反本协议造成我方损失的，你方负完全的赔偿责任。  
 **只有完全同意以上协议，你才可以使用本软件。**  
 **如果不同意以上协议，不要使用本软件。**    


# 四、如何使用
目前这里只是一个广告宣传的渠道，请到  http://giveda.com/  获取最新代码   
查看如下《简易指导文档》：   
https://gitee.com/giveda/GOSP/blob/master/HowTo.md  
欢迎加入QQ交流群：914464844   


# 五、效果演示  

![Giveda](docs/images/configureResult1.jpeg)

![Giveda](docs/images/gCtrlButton.jpeg)

![Giveda](docs/images/gCtrlIconView.jpeg)

![Giveda](docs/images/gCtrlItem.jpeg)

![Giveda](docs/images/gCtrlLineEdit.jpeg)

![Giveda](docs/images/gCtrlListBox.jpeg)

![Giveda](docs/images/gCtrlMsgBox.jpeg)

![Giveda](docs/images/gCtrlProgressBar.jpeg)

![Giveda](docs/images/gCtrlRadioButton.jpeg)

![Giveda](docs/images/debugInfo.jpeg)

![在docs/images/目录下](docs/images/DVB_768x432.gif)

![在doc/images/目录下](docs/images/DVB_edit_chnl_768x432.gif)

![在doc/images/目录下](docs/images/DVB_mainMenu_768x432_png.gif)

https://gitee.com/giveda/GOSP/tree/master/docs/images/DVB_768x432.gif  
https://gitee.com/giveda/GOSP/tree/master/docs/images/DVB_768x432_large.gif  
https://gitee.com/giveda/GOSP/tree/master/docs/images/DVB_edit_chnl_768x432.gif  
https://gitee.com/giveda/GOSP/tree/master/docs/images/DVB_mainMenu_768x432_png.gif  


# 六、写在最后  
  **这是一个处于筹划过程中的项目，视情况而定。如果你觉得本软件有用，应该有钱出钱、有力出力、支持本项目向你期望的方向发展。我只是在有兴趣的时候，做一点自己感兴趣的事情。**   
  **作者的联系电话：18676768949（可加微信）**   
