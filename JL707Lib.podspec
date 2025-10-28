#
# Be sure to run `pod lib lint EAModularity.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'JL707Lib'
  s.version          = '1.0.0.2'
  s.summary          = 'A short description of JLLogHelper.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/EastApex/EASDKTool_iOS'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'Aye' => 'aye.zhang@qq.com' }
  s.source           = { :git => 'https://github.com/EastApex/EASDKTool_iOS.git', :tag => s.version.to_s }

  s.ios.deployment_target = '9.0'
  
  s.libraries = 'c++'

  s.dependency 'zipzap'
  
 
  

  s.vendored_frameworks = [
    'JL707Lib/JLLogHelper.framework',
    'JL707Lib/JL_OTALib.framework',
    'JL707Lib/JL_HashPair.framework',
    'JL707Lib/JL_BLEKit.framework',
    'JL707Lib/JL_AdvParse.framework',
    'JL707Lib/JLDialUnit.framework',
    'JL707Lib/JLBmpConvertKit.framework'
  ]



  
end
