const { ipcRenderer } = require('electron')
console.log('doing nothing')

window.addEventListener('message', (event) => {
  ipcRenderer.send('leak-result', event.data)
})
