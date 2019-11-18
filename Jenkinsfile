pipeline {
 agent {
   label "jenkins-maven"
 }
 stages {
   stage('build pyinstaller onefile app') {
     steps {
       container('maven') {
         sh "docker build -t sensedata1/audio-format-detective:latest ."
         sh "docker run -i -v /var/jenkins_home:/var/jenkins_home sensedata1/audio-format-detective:latest"
       }
     }
   }
 }
}


