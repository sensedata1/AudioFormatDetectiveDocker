pipeline {
    agent { dockerfile true }
    stages {
        stage('Test') {
            steps {
             sh "docker build -t sensedata1/audio-format-detective:latest ."
             sh "docker run -i -v /var/jenkins_home:/var/jenkins_home sensedata1/audio-format-detective:latest"
            }
        }
    }
}
